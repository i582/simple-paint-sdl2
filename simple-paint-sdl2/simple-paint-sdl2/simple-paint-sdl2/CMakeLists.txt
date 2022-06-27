cmake_minimum_required(VERSION 3.21)
project(paint_sdl2)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

#set(SDL2_PATH "/opt/homebrew/include/SDL2")
#set(SDL2_image "/opt/homebrew/include/SDL2")

include_directories(modules/colors)
include_directories(modules/controls)
include_directories(modules/editor)
include_directories(modules/events)
include_directories(modules/layers_viewer)
include_directories(modules/layers_viewer/layer_view)
include_directories(modules/menubar)
include_directories(modules/menubar/menu_item)
include_directories(modules/primitives)
include_directories(modules/resources)
include_directories(modules/styles)
include_directories(modules/toolbar)
include_directories(modules/toolbar/tools)
include_directories(modules/viewport)
include_directories(modules/viewport/canvas)
include_directories(modules/viewport/canvas/layers)
include_directories(modules/viewport/canvas/layers/layer)
include_directories(modules/viewport/scrolls)
include_directories(modules/window)
include_directories(modules/window/types/main)
include_directories(modules/window/types/new_doc)

add_executable(paint_sdl2
        modules/colors/color.cpp
        modules/colors/color.h
        modules/controls/_Control.cpp
        modules/controls/_Control.h
        modules/controls/button.cpp
        modules/controls/button.h
        modules/controls/button_image.cpp
        modules/controls/button_image.h
        modules/controls/Checkbox.cpp
        modules/controls/Checkbox.h
        modules/controls/DropDown.cpp
        modules/controls/DropDown.h
        modules/controls/DropWindow.cpp
        modules/controls/DropWindow.h
        modules/controls/HScroll.cpp
        modules/controls/HScroll.h
        modules/controls/input.cpp
        modules/controls/input.h
        modules/controls/label.cpp
        modules/controls/label.h
        modules/controls/RadioButton.cpp
        modules/controls/RadioButton.h
        modules/controls/scale_info.cpp
        modules/controls/scale_info.h
        modules/controls/scroll.cpp
        modules/controls/scroll.h
        modules/controls/VScroll.cpp
        modules/controls/VScroll.h
        modules/editor/editor.cpp
        modules/editor/editor.h
        modules/editor/editor_event.cpp
        modules/editor/editor_user_event.cpp
        modules/events/events.cpp
        modules/events/events.h
        modules/layers_viewer/layer_view/layer_view.cpp
        modules/layers_viewer/layer_view/layer_view.h
        modules/layers_viewer/layers_viewer.cpp
        modules/layers_viewer/layers_viewer.h
        modules/menubar/menu_item/menu_item.cpp
        modules/menubar/menu_item/menu_item.h
        modules/menubar/menubar.cpp
        modules/menubar/menubar.h
        modules/primitives/primitives.cpp
        modules/primitives/primitives.h
        modules/resources/resources.cpp
        modules/resources/resources.h
        modules/styles/styles.cpp
        modules/styles/styles.h
        modules/toolbar/tools/tool.cpp
        modules/toolbar/tools/tool.h
        modules/toolbar/toolbar.cpp
        modules/toolbar/toolbar.h
        modules/viewport/canvas/layers/layer/layer.cpp
        modules/viewport/canvas/layers/layer/layer.h
        modules/viewport/canvas/layers/layers.cpp
        modules/viewport/canvas/layers/layers.h
        modules/viewport/canvas/canvas.cpp
        modules/viewport/canvas/canvas.h
        modules/viewport/canvas/canvas_event.cpp
        modules/viewport/scrolls/h_view_scroll.cpp
        modules/viewport/scrolls/h_view_scroll.h
        modules/viewport/scrolls/v_view_scroll.cpp
        modules/viewport/scrolls/v_view_scroll.h
        modules/viewport/viewport.cpp
        modules/viewport/viewport.h
        modules/viewport/viewport_events.cpp
        modules/window/types/main/main-window.cpp
        modules/window/types/main/main-window.h
        modules/window/types/main/main-window_event.cpp
        modules/window/types/main/main-window_user_events.cpp
        modules/window/types/new_doc/WindowNeDocument_user_events.cpp
        modules/window/types/new_doc/WindowNewDocument.cpp
        modules/window/types/new_doc/WindowNewDocument.h
        modules/window/types/new_doc/WindowNewDocument_events.cpp
        modules/window/window.cpp
        modules/window/window.h
        modules/window/window_event.cpp
        main.cpp)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

target_link_libraries(paint_sdl2 ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})

# Link SDL2::Main, SDL2::Image and SDL2::GFX to our project
#target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image SDL2::TTF)