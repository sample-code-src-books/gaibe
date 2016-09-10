##TODO configuration for preprocessor definitions: configuration | platform
cmake_minimum_required(VERSION 2.8)
project(WestWorld1)

###########################
## Setting up the builds ##
###########################
# settings for modern c++
set(DEBUG_FLAGS "")#"-std=c++11 -g -O1 -Wall -Wextra -Werror -pedantic")
set(RELEASE_FLAGS "")#"-std=c++11 -O3 -Wall -Wextra -Werror -pedantic")

set(CMAKE_CXX_FLAGS ${RELEASE_FLAGS})
set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_CONFIGURATION_TYPES Debug Release)
# two build targets: debug 32-bit, release 32-bit

##############################
## Group & Folder Structure ##
##############################

##set a variable for grouping
#set( MATH_LIBRARY ${MATH_LIBRARY}
#  //... group sources
#)
##now set that this shows up as a filter in the project file
#source_group("Math" FILES ${MATH_LIBRARY})

set( SRC_FILES ${SRC_FILES}
  BaseGameEntity.cpp
  main.cpp
  Miner.cpp
  MinerOwnedStates.cpp
)
source_group("Source Files" FILES ${SRC_FIlES})

set( HEADER_FILES ${HEADER_FILES}
  BaseGameEntity.h
  ../../Common/misc/ConsoleUtils.h
  EntityNames.h
  Locations.h
  Miner.h
  MinerOwnedStates.h
  State.h
)
source_group("Header Files" FILES ${HEADER_FIlES})

#################
## Executables ##
#################
add_executable(WestWorld1
  ${SRC_FILES}
  ${HEADER_FILES}
)


