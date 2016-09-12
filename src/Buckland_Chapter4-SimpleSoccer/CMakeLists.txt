cmake_minimum_required(VERSION 2.8)
project(SimpleSoccer)

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

set(SRC_FILES ${SRC_FILES}
  main.cpp
  ParamLoader.cpp
  SoccerPitch.cpp
  SoccerTeam.cpp
  SteeringBehaviors.cpp
  SupportSpotCalculator.cpp
)
source_group("Source Files" FILES ${SRC_FIlES})


set(HEADER_FILES ${HEADER_FILES}
  constants.h
  Goal.h
  ParamLoader.h
  SoccerPitch.h
  SoccerTeam.h
  SteeringBehaviors.h
  SupportSpotCalculator.h
)
source_group("Header Files" FILES ${HEADER_FIlES})


set(RESOURCE_FILES ${RESOURCE_FILES}
  resource.h
  icon1.ico
  Params.ini
  Script1.rc
)
source_group("Resource Files" FILES ${RESOURCE_FILES})


set(STATE_AND_STATE_MACHINE_FILES ${STATE_AND_STATE_MACHINE_FILES}
  FieldPlayerStates.cpp
  GoalKeeperStates.cpp
  TeamStates.cpp
)
source_group("States and State Machine" FILES ${STATE_AND_STATE_MACHINE_FILES})


set(MESSAGING_FILES ${MESSAGING_FILES}
  SoccerMessages.h
  SoccerMessages.cpp
  ../Common/Messaging/Telegram.h
  ../Common/Messaging/MessageDispatcher.h
  ../Common/Messaging/MessageDispatcher.cpp

)
source_group("Messaging" FILES ${MESSAGING_FILES})



set(ENTITY_RELATED_FILES ${ENTITY_RELATED_FILES}
  ../Common/Game/EntityFunctionTemplates.h
  ../Common/Game/BaseGameEntity.h
  ../Common/Game/BaseGameEntity.cpp
  ../Common/Game/EntityManager.h
  ../Common/Game/EntityManager.cpp
  FieldPlayer.h
  FieldPlayer.cpp
  Goalkeeper.h
  Goalkeeper.cpp
  PlayerBase.h
  PlayerBase.cpp
  SoccerBall.h
  SoccerBall.cpp
)
source_group("Entity Related" FILES ${ENTITY_RELATED_FILES})


set(COMMON_FILES ${COMMON_FILES}

  ../Common/2D/Vector2d.cpp
  ../Common/Debug/DebugConsole.cpp
  ../Common/misc/Cgdi.cpp
  ../Common/misc/FrameCounter.cpp
  ../Common/misc/iniFileLoaderBase.cpp
  ../Common/misc/WindowUtils.cpp
  ../Common/Time/PrecisionTimer.cpp

  ../Common/2D/C2DMatrix.h
  ../Common/2D/geometry.h
  ../Common/2D/Transformations.h
  ../Common/2D/Vector2D.h
  ../Common/2D/Wall2D.h
  ../Common/Debug/DebugConsole.h
  ../Common/Game/Region.h
  ../Common/misc/autolist.h
  ../Common/misc/Cgdi.h
  ../Common/misc/FrameCounter.h
  ../Common/misc/iniFileLoaderBase.h
  ../Common/misc/utils.h
  ../Common/misc/WindowUtils.h
  ../Common/Time/PrecisionTimer.h
  ../Common/Time/Regulator.h
)
source_group("Common" FILES ${COMMON_FILES})

#################
## Executables ##
#################
add_executable(SimpleSoccer
  ${SRC_FILES}
  ${HEADER_FILES}
  ${RESOURCE_FILES}
  ${STATE_AND_STATE_MACHINE_FILES}
  ${MESSAGING_FILES}
  ${ENTITY_RELATED_FILES}
  ${COMMON_FILES}
)
