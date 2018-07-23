cmake_minimum_required(VERSION 3.10)
project(tabula_rasa)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(include/TabulaRasa
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIRS})

add_library(tabula_rasa include/TabulaRasa/Camera2D.h include/TabulaRasa/Errors.h include/TabulaRasa/GLSLProgram.h
        include/TabulaRasa/GLTexture.h include/TabulaRasa/ImageLoader.h include/TabulaRasa/InputManager.h
        include/TabulaRasa/IOManager.h include/TabulaRasa/picoPNG.h include/TabulaRasa/ResourceManager.h
        include/TabulaRasa/Sprite.h include/TabulaRasa/SpriteBatch.h include/TabulaRasa/TabulaRasa.h
        include/TabulaRasa/TextureCache.h include/TabulaRasa/Timing.h include/TabulaRasa/Vertex.h
        include/TabulaRasa/Window.h include/TabulaRasa/GameObject.h include/TabulaRasa/Drawable.h

        src/Camera2D.cpp src/Errors.cpp src/GLSLProgram.cpp src/ImageLoader.cpp src/InputManager.cpp src/IOManager.cpp
        src/picoPNG.cpp src/ResourceManager.cpp src/Sprite.cpp src/SpriteBatch.cpp src/TabulaRasa.cpp src/TextureCache.cpp
        src/Timing.cpp src/Window.cpp src/GameObject.cpp src/Drawable.cpp)