#---------------------------------------------------------------------------------------------------------------------
# Project Settings
#---------------------------------------------------------------------------------------------------------------------
TARGET       :=  $(notdir $(CURDIR))
BUILD        :=  build
LIBBUTANO    :=  ../../butano
PYTHON       :=  python3
SOURCES      := src src/actors src/behaviors src/managers src/scenes src/utils ../common/src
INCLUDES     := include src src/actors src/behaviors src/managers src/scenes src/utils ../common/include
DATA         :=
GRAPHICS     :=  graphics ../common/graphics
AUDIO        :=  
DMGAUDIO     :=  
ROMTITLE     :=  Hit Detection
ROMCODE      :=  SBTP
USERFLAGS    :=  
USERCXXFLAGS :=  
USERASFLAGS  :=  
USERLDFLAGS  :=  
USERLIBDIRS  :=  
USERLIBS     :=  
DEFAULTLIBS  :=  
STACKTRACE   :=  
USERBUILD    :=  
EXTTOOL      :=  

#---------------------------------------------------------------------------------------------------------------------
# Export absolute butano path:
#---------------------------------------------------------------------------------------------------------------------
ifndef LIBBUTANOABS
	export LIBBUTANOABS := $(realpath $(LIBBUTANO))
endif

#---------------------------------------------------------------------------------------------------------------------
# Include main makefile:
#---------------------------------------------------------------------------------------------------------------------
include $(LIBBUTANOABS)/butano.mak

#---------------------------------------------------------------------------------------------------------------------
# Custom step: Run the game automatically in mGBA after the build
#---------------------------------------------------------------------------------------------------------------------
run: all
	@echo "Launching mGBA with $(TARGET).gba..."
	/Applications/mGBA.app/Contents/MacOS/mgba --debug $(TARGET).gba

.PHONY: run
