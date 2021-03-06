CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT("Murakami")

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
SET(CMAKE_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/include/" ${CMAKE_INCLUDE_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
SET(EXECUTABLE_NAME "murakami")

IF (CMAKE_BUILD_TYPE STREQUAL "")
	SET(CMAKE_BUILD_TYPE Release)
ENDIF ()

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/include/")
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/lib/glm")

FILE(GLOB_RECURSE MY_SRC "src/*.cpp")
FILE(GLOB_RECURSE MY_INC "include/*.h")

ADD_EXECUTABLE(${EXECUTABLE_NAME} ${MY_SRC} ${MY_INC})

INCLUDE(SetCompilerFlags)

FIND_PACKAGE(OpenGL REQUIRED)

FIND_PACKAGE(GLEW REQUIRED)
IF (GLEW_FOUND)
	INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
ENDIF ()

FIND_PACKAGE(SFML 2 REQUIRED system window graphics network audio)
IF (SFML_FOUND)
	INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
ENDIF ()

FIND_PACKAGE(Bullet REQUIRED)
IF (BULLET_FOUND)
	INCLUDE_DIRECTORIES(${BULLET_INCLUDE_DIRS})
ENDIF ()

TARGET_LINK_LIBRARIES(${EXECUTABLE_NAME}
	${OPENGL_LIBRARIES}
	${GLEW_LIBRARIES}
	${SFML_LIBRARIES}
	${BULLET_LIBRARIES}
)
