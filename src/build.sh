g++ -g -I/usr/include -I../include \
    main.cpp \
    SXShape.cpp \
    SXTexture.cpp \
    surface/SXSurface.cpp \
    SXRender.cpp \
    SXWindow.cpp \
    surface/SXTextSurface.cpp \
    surface/SXBMPSurface.cpp \
    SXLabel.cpp \
    SXWidget.cpp \
    `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
