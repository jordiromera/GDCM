/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http:/gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/


/*
 * See TestReaderUpToTag
 */
struct StreamOffset
{
  const char *filename;
  std::streamoff offset;
};

static const StreamOffset gdcmStreamOffsetDataFiles[] = {
{ "00191113.dcm",934 },
{ "00191113.dcm",934 },
{ "012345.002.050.dcm",9604 },
{ "05115014-mr-siemens-avanto-syngo-with-palette-icone.dcm",41948 },
{ "05148044-mr-siemens-avanto-syngo.dcm",55884 },
{ "3E768EB7.dcm",3234 },
{ "ACUSON-24-YBR_FULL-RLE-b.dcm",2032 },
{ "ACUSON-24-YBR_FULL-RLE.dcm",1920 },
{ "ALOKA_SSD-8-MONO2-RLE-SQ.dcm",1398 },
{ "AMIInvalidPrivateDefinedLengthSQasUN.dcm", 12744 },
{ "BugGDCM2_UndefItemWrongVL.dcm",9570 },
{ "CR-MONO1-10-chest.dcm",776 },
{ "CT-MONO2-12-lomb-an2.acr",1230 },
{ "CT-MONO2-16-ankle.dcm",1148 },
{ "CT-MONO2-16-brain.dcm",1680 },
{ "CT-MONO2-16-chest.dcm",1638 },
{ "CT-MONO2-16-ort.dcm",1674 },
{ "CT-MONO2-8-abdo.dcm",796 },
{ "CT-SIEMENS-Icone-With-PaletteColor.dcm",8162 },
{ "CT-SIEMENS-MissingPixelDataInIconSQ.dcm",20504 },
{ "CT_16b_signed-UsedBits13.dcm",2582 },
{ "DCMTK_JPEGExt_12Bits.dcm",796 },
{ "DICOMDIR",-1 },
{ "DICOMDIR-Philips-EasyVision-4200-Entries",-1 },
{ "DICOMDIR_MR_B_VA12A",-1 },
{ "DMCPACS_ExplicitImplicit_BogusIOP.dcm",66618 },
{ "DX_GE_FALCON_SNOWY-VOI.dcm",104014 },
{ "DX_J2K_0Padding.dcm",1494 },
{ "D_CLUNIE_CT1_J2KI.dcm",6596 },
{ "D_CLUNIE_CT1_J2KR.dcm",6496 },
{ "D_CLUNIE_CT1_JLSL.dcm", 6464 },
{ "D_CLUNIE_CT1_JLSN.dcm", 6578 },
{ "D_CLUNIE_CT1_JPLL.dcm",6468 },
{ "D_CLUNIE_CT1_RLE.dcm",6402 },
{ "D_CLUNIE_CT2_JPLL.dcm",1756 },
{ "D_CLUNIE_CT2_RLE.dcm",1688 },
{ "D_CLUNIE_MR1_JPLL.dcm",1762 },
{ "D_CLUNIE_MR1_JPLY.dcm",1848 },
{ "D_CLUNIE_MR1_RLE.dcm",1694 },
{ "D_CLUNIE_MR2_JPLL.dcm",1958 },
{ "D_CLUNIE_MR2_JPLY.dcm",2046 },
{ "D_CLUNIE_MR2_RLE.dcm",1890 },
{ "D_CLUNIE_MR3_JPLL.dcm",9582 },
{ "D_CLUNIE_MR3_JPLY.dcm",9670 },
{ "D_CLUNIE_MR3_RLE.dcm",9516 },
{ "D_CLUNIE_MR4_JPLL.dcm",1980 },
{ "D_CLUNIE_MR4_JPLY.dcm",2068 },
{ "D_CLUNIE_MR4_RLE.dcm",1912 },
{ "D_CLUNIE_NM1_JPLL.dcm",2902 },
{ "D_CLUNIE_NM1_JPLY.dcm",2990 },
{ "D_CLUNIE_NM1_RLE.dcm",2838 },
{ "D_CLUNIE_RG1_JPLL.dcm",1870 },
{ "D_CLUNIE_RG1_RLE.dcm",1806 },
{ "D_CLUNIE_RG2_JPLL.dcm",1456 },
{ "D_CLUNIE_RG2_JPLY.dcm",1544 },
{ "D_CLUNIE_RG2_RLE.dcm",1380 },
{ "D_CLUNIE_RG3_JPLL.dcm",1526 },
{ "D_CLUNIE_RG3_JPLY.dcm",1614 },
{ "D_CLUNIE_RG3_RLE.dcm",1444 },
{ "D_CLUNIE_SC1_JPLY.dcm",1352 },
{ "D_CLUNIE_SC1_RLE.dcm",1188 },
{ "D_CLUNIE_US1_RLE.dcm",1318 },
{ "D_CLUNIE_VL1_RLE.dcm",1200 },
{ "D_CLUNIE_VL2_RLE.dcm",1198 },
{ "D_CLUNIE_VL3_RLE.dcm",1210 },
{ "D_CLUNIE_VL4_RLE.dcm",1192 },
{ "D_CLUNIE_VL6_RLE.dcm",1210 },
{ "D_CLUNIE_XA1_JPLL.dcm",1204 },
{ "D_CLUNIE_XA1_JPLY.dcm",1292 },
{ "D_CLUNIE_XA1_RLE.dcm",1128 },
{ "DermaColorLossLess.dcm",940 },
{ "ELSCINT1_JP2vsJ2K.dcm",1820 },
{ "ELSCINT1_PMSCT_RLE1.dcm",-1 },
{ "ExplicitVRforPublicElementsImplicitVRforShadowElements.dcm",9538 },
{ "FUJI-10-MONO1-ACR_NEMA_2.dcm",862 },
{ "GE_CT_With_Private_compressed-icon.dcm",10810 },
{ "GE_DLX-8-MONO2-Multiframe-Jpeg_Lossless.dcm",14138 },
{ "GE_DLX-8-MONO2-Multiframe.dcm",4984 },
{ "GE_DLX-8-MONO2-PrivateSyntax.dcm",2920 },
{ "GE_GENESIS-16-MONO2-Uncompressed-UnusualVR.dcm",9666 },
{ "GE_GENESIS-16-MONO2-WrongLengthItem.dcm",1930 },
{ "GE_LOGIQBook-8-RGB-HugePreview.dcm",935608 },
{ "GE_MR_0025xx1bProtocolDataBlock.dcm",11882 },
{ "GE_RHAPSODE-16-MONO2-JPEG-Fragments.dcm",6468 },
{ "ITK_GDCM124_MultiframeSecondaryCaptureInvalid.dcm",1144 },
{ "JDDICOM_Sample2-dcmdjpeg.dcm",848 },
{ "JDDICOM_Sample2.dcm",834 },
{ "JPEGDefinedLengthSequenceOfFragments.dcm",2874 },
{ "JPEG_LossyYBR.dcm",2378 },
{ "KODAK-12-MONO1-Odd_Terminated_Sequence.dcm",9134 },
{ "KODAK_CompressedIcon.dcm",8646 },
{ "LEADTOOLS_FLOWERS-16-MONO2-JpegLossless.dcm",1944 },
{ "LEADTOOLS_FLOWERS-16-MONO2-RLE.dcm",1942 },
{ "LEADTOOLS_FLOWERS-16-MONO2-Uncompressed.dcm",1942 },
{ "LEADTOOLS_FLOWERS-24-RGB-JpegLossless.dcm",1936 },
{ "LEADTOOLS_FLOWERS-24-RGB-JpegLossy.dcm",1936 },
{ "LEADTOOLS_FLOWERS-24-RGB-Uncompressed.dcm",1934 },
{ "LEADTOOLS_FLOWERS-8-MONO2-JpegLossy.dcm",1944 },
{ "LEADTOOLS_FLOWERS-8-MONO2-RLE.dcm",1942 },
{ "LEADTOOLS_FLOWERS-8-MONO2-Uncompressed.dcm",1942 },
{ "LEADTOOLS_FLOWERS-8-PAL-RLE.dcm",3538 },
{ "LEADTOOLS_FLOWERS-8-PAL-Uncompressed.dcm",3538 },
{ "LIBIDO-8-ACR_NEMA-Lena_128_128.acr",182 },
{ "LJPEG_BuginGDCM12.dcm",2248 },
{ "MARCONI_MxTWin-12-MONO2-JpegLossless-ZeroLengthSQ.dcm",1916 },
{ "MAROTECH_CT_JP2Lossy.dcm",33856 },
{ "MR-Brucker-CineTagging-NonSquarePixels.dcm",1542 },
{ "MR-MONO2-12-an2.acr",1866 },
{ "MR-MONO2-12-angio-an1.acr",650 },
{ "MR-MONO2-12-shoulder.dcm",1580 },
{ "MR-MONO2-16-head.dcm",1804 },
{ "MR-MONO2-8-16x-heart.dcm",920 },
{ "MR-SIEMENS-DICOM-WithOverlays-extracted-overlays.dcm", 42612 },
{ "MR-SIEMENS-DICOM-WithOverlays.dcm",42416 },
{ "MR16BitsAllocated_8BitsStored.dcm",940 },
{ "MR_ELSCINT1_00e1_1042_SQ_feff_00e0_Item.dcm",7704 },
{ "MR_GE_with_Private_Compressed_Icon_0009_1110.dcm",20712 },
{ "MR_Philips-Intera_BreaksNOSHADOW.dcm",7626 },
{ "MR_Philips_Intera_No_PrivateSequenceImplicitVR.dcm",9508 },
{ "MR_Philips_Intera_PrivateSequenceExplicitVR_in_SQ_2001_e05f_item_wrong_lgt_use_NOSHADOWSEQ.dcm",7524 },
{ "MR_Philips_Intera_PrivateSequenceImplicitVR.dcm",7026 },
{ "MR_Philips_Intera_SwitchIndianess_noLgtSQItem_in_trueLgtSeq.dcm",9276 },
{ "MR_SIEMENS_forceLoad29-1010_29-1020.dcm",60564 },
{ "MR_Spectroscopy_SIEMENS_OF.dcm",-1 },
{ "NM-MONO2-16-13x-heart.dcm",1234 },
{ "OT-MONO2-8-a7.dcm",438 },
{ "OT-PAL-8-face.dcm",1654 },
{ "OsirixFake16BitsStoredFakeSpacing.dcm",1318 },
{ "PHILIPS_Brilliance_ExtraBytesInOverlay.dcm",34550 },
{ "PHILIPS_GDCM12xBug.dcm",9338 },
{ "PHILIPS_GDCM12xBug2.dcm",9670 },
{ "PHILIPS_Gyroscan-12-MONO2-Jpeg_Lossless.dcm",15378 },
{ "PHILIPS_Gyroscan-8-MONO2-Odd_Sequence.dcm", 6584 },
{ "PHILIPS_Intera-16-MONO2-Uncompress.dcm",9276 },
{ "PICKER-16-MONO2-Nested_icon.dcm",18228 },
{ "PICKER-16-MONO2-No_DicomV3_Preamble.dcm",1406 },
{ "PrivateGEImplicitVRBigEndianTransferSyntax16Bits.dcm",14972 },
{ "RadBWLossLess.dcm",942 },
{ "SIEMENS-12-Jpeg_Process_2_4-Lossy-a.dcm",3044 },
{ "SIEMENS-MR-RGB-16Bits.dcm",49852 },
{ "SIEMENS_CSA2.dcm",104352 },
{ "SIEMENS_ImageLocationUN.dcm",6348 },
{ "SIEMENS_MAGNETOM-12-ACR_NEMA_2-Modern.dcm",6052 },
{ "SIEMENS_MAGNETOM-12-MONO2-FileSeq0.dcm",6430 },
{ "SIEMENS_MAGNETOM-12-MONO2-FileSeq1.dcm",6430 },
{ "SIEMENS_MAGNETOM-12-MONO2-FileSeq2.dcm",6430 },
{ "SIEMENS_MAGNETOM-12-MONO2-FileSeq3.dcm",6430 },
{ "SIEMENS_MAGNETOM-12-MONO2-GDCM12-VRUN.dcm",5170 },
{ "SIEMENS_MAGNETOM-12-MONO2-Uncompressed.dcm",5160 },
{ "SIEMENS_MAGNETOM-12-MONO2-VRUN.dcm",5302 },
{ "SIEMENS_MOSAIC_12BitsStored-16BitsJPEG.dcm",105726 },
{ "SIEMENS_SOMATOM-12-ACR_NEMA-ZeroLengthUs.acr",5064 },
{ "SIEMENS_Sonata-12-MONO2-SQ.dcm",51804 },
{ "SIEMENS_Sonata-16-MONO2-Value_Multiplicity.dcm",25686 },
{ "SignedShortLosslessBug.dcm",1784 },
{ "TG18-CH-2k-01.dcm",2308 },
{ "THERALYS-12-MONO2-Uncompressed-Even_Length_Tag.dcm",1839 },
{ "TOSHIBA_MRT150-16-MONO2-ACR_NEMA_2.dcm",1130 },
{ "TheralysGDCM120Bug.dcm",8442 },
{ "US-GE-4AICL142.dcm",14072 },
{ "US-IRAD-NoPreambleStartWith0003.dcm",3330 },
{ "US-IRAD-NoPreambleStartWith0005.dcm",2490 },
{ "US-MONO2-8-8x-execho.dcm",976 },
{ "US-PAL-8-10x-echo.dcm",2428 },
{ "US-RGB-8-epicard.dcm",1012 },
{ "US-RGB-8-esopecho.dcm",904 },
{ "XA-MONO2-8-12x-catheter.dcm",1006 },
{ "dicomdir_Acusson_WithPrivate_WithSR",-1 },
{ "dicomdir_Pms_WithVisit_WithPrivate_WithStudyComponents",-1 },
{ "dicomdir_Pms_With_heavy_embedded_sequence",-1 },
{ "dicomdir_With_embedded_icons",-1 },
{ "fffc0000UN.dcm",1154 },
{ "gdcm-ACR-LibIDO.acr",182 },
{ "gdcm-CR-DCMTK-16-NonSamplePerPix.dcm",740 },
{ "gdcm-JPEG-Extended.dcm",2946 },
{ "gdcm-JPEG-LossLess3a.dcm",2540 },
{ "gdcm-JPEG-LossLessThoravision.dcm",3144 },
{ "gdcm-MR-PHILIPS-16-Multi-Seq.dcm",35846 },
{ "gdcm-MR-PHILIPS-16-NonSquarePixels.dcm",5010 },
{ "gdcm-MR-SIEMENS-16-2.acr",6052 },
{ "gdcm-US-ALOKA-16.dcm",258740 },
{ "libido1.0-vol.acr",170 },
{ "rle16loo.dcm",394226 },
{ "rle16sti.dcm",394170 },
{ "simpleImageWithIcon.dcm",17478 },
{ "test.acr",182 },
{ "undefined_length_un_vr.dcm",9168 },
{ "IM-0001-0066.CommandTag00.dcm", 3050 },
{ "PHILIPS_Gyroscan-12-Jpeg_Extended_Process_2_4.dcm", 5956 },
{ "UnexpectedSequenceDelimiterInFixedLengthSequence.dcm", 4190 },
{ "GDCMJ2K_TextGBR.dcm", 770 },
{ "NM_Kakadu44_SOTmarkerincons.dcm", 1576 },

/* Stopping condition */
{ 0 ,0 },
};
