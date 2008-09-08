/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2008 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "gdcmImageFragmentSplitter.h"
#include "gdcmTesting.h"
#include "gdcmSystem.h"
#include "gdcmImageReader.h"
#include "gdcmImageWriter.h"
#include "gdcmImage.h"

int TestImageFragmentSplitterFunc(const char *filename, bool verbose = false)
{
  gdcm::ImageReader reader;
  reader.SetFileName( filename );
  if ( !reader.Read() )
    {
    const gdcm::FileMetaInformation &header = reader.GetFile().GetHeader();
    gdcm::MediaStorage ms = header.GetMediaStorage();
    bool isImage = gdcm::MediaStorage::IsImage( ms );
    if( isImage )
      {
      std::cout << "Could not read: " << filename << std::endl;
      return 1;
      }
    return 0;
    }
  const gdcm::Image &image = reader.GetImage();

  gdcm::ImageFragmentSplitter splitter;
  splitter.SetInput( image );
  splitter.SetFragmentSizeMax( 65536 );
  bool b = splitter.Split();
  if( !b )
    {
    std::cerr << "Could not apply splitter: " << filename << std::endl;
    return 1;
    }

  // Create directory first:
  const char subdir[] = "TestImageFragmentSplitter";
  std::string tmpdir = gdcm::Testing::GetTempDirectory( subdir );
  if( !gdcm::System::FileIsDirectory( tmpdir.c_str() ) )
    {
    gdcm::System::MakeDirectory( tmpdir.c_str() );
    //return 1;
    }
  std::string outfilename = gdcm::Testing::GetTempFilename( filename, subdir );

  gdcm::ImageWriter writer;
  writer.SetFileName( outfilename.c_str() );
  //writer.SetFile( reader.GetFile() ); // increase test goal
  writer.SetImage( splitter.GetOutput() );
  if( !writer.Write() )
    {
    std::cerr << "Failed to write: " << outfilename << std::endl;
    return 1;
    }
    std::cerr << "Success to write: " << outfilename << std::endl;

  return 0;
}

int TestImageFragmentSplitter(int argc, char *argv[])
{
  if( argc == 2 )
    {
    const char *filename = argv[1];
    return TestImageFragmentSplitterFunc(filename, true);
    }

  // else
  gdcm::Trace::DebugOff();
  gdcm::Trace::WarningOff();
  int r = 0, i = 0;
  const char *filename;
  const char * const *filenames = gdcm::Testing::GetFileNames();
  while( (filename = filenames[i]) )
    {
    r += TestImageFragmentSplitterFunc( filename );
    ++i;
    }

  return r;
}