set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_CXX_STANDARD 14)

project(zombiez)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(../TabulaRasa/include include
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIRS})

add_executable(zombiez src/main.cpp src/MainGame.cpp include/GameObject.h include/Drawable.h src/Drawable.cpp include/MainGame.h src/Bullet.cpp include/Bullet.h src/GameObject.cpp include/Level.h include/Actor.h include/Updatable.h src/Level.cpp src/Actor.cpp)
target_link_libraries(zombiez tabula_rasa ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES})
if (APPLE)
    target_link_libraries(zombiez "-framework OpenGL")
endif()