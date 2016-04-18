CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

SET(TARGET "composite")

#  SET(TARGET_SRC ${TARGET_SRC}  ${TARGET_INC})
#  SET(TARGET_SRC
#    ${TARGET}.cc
#    )

FILE(GLOB_RECURSE TARGET_INC  "include/*.h")
FILE(GLOB_RECURSE TARGET_SRC  "src/*.cpp")


FIND_PACKAGE(deal.II 8.3 QUIET
  HINTS
    ${deal.II_DIR} ${DEAL_II_DIR} ../ ../../  $ENV{DEAL_II_DIR} ../../deal.II/
  )
IF(NOT ${deal.II_FOUND})
  MESSAGE(FATAL_ERROR "\n"
    "*** Could not locate a (sufficiently recent) version of deal.II. ***\n\n"
    "You may want to either pass a flag -DDEAL_II_DIR=/path/to/deal.II to cmake\n"
    "or set an environment variable \"DEAL_II_DIR\" that contains this path."
    )
ENDIF ()

#
# Are all dependencies fullfilled?
#
IF(NOT DEAL_II_WITH_PETSC)
  MESSAGE(FATAL_ERROR "
Error! The deal.II library found at ${DEAL_II_PATH} was not configured with
    DEAL_II_WITH_PETSC = ON
One or all of these are OFF in your installation but are required for this tutorial step."
    )
ENDIF()

DEAL_II_INITIALIZE_CACHED_VARIABLES()
PROJECT(${TARGET})
DEAL_II_INVOKE_AUTOPILOT()
