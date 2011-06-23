#
#  Copyright (c) 2006-2011 Mathieu Malaterre <mathieu.malaterre@gmail.com>
#
#  Redistribution and use is allowed according to the terms of the New
#  BSD license.
#  For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

FIND_PATH(POPPLER_INCLUDE_DIR poppler/poppler-config.h
/usr/local/include
/usr/include
)

FIND_LIBRARY(POPPLER_LIBRARY
  NAMES poppler
  PATHS /usr/lib /usr/local/lib
  )

IF (POPPLER_LIBRARY AND POPPLER_INCLUDE_DIR)
    SET(POPPLER_LIBRARIES ${POPPLER_LIBRARY})
    SET(POPPLER_INCLUDE_DIRS ${POPPLER_INCLUDE_DIR} ${POPPLER_INCLUDE_DIR}/poppler)
    SET(POPPLER_FOUND "YES")
ELSE (POPPLER_LIBRARY AND POPPLER_INCLUDE_DIR)
  SET(POPPLER_FOUND "NO")
ENDIF (POPPLER_LIBRARY AND POPPLER_INCLUDE_DIR)

IF (POPPLER_FOUND)
   IF (NOT Poppler_FIND_QUIETLY)
      MESSAGE(STATUS "Found POPPLER: ${POPPLER_LIBRARIES}")
   ENDIF ()
ELSE (POPPLER_FOUND)
   IF (Poppler_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find POPPLER library")
   ENDIF ()
ENDIF (POPPLER_FOUND)

MARK_AS_ADVANCED(
  POPPLER_LIBRARY
  POPPLER_INCLUDE_DIR
  )
