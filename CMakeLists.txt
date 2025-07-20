CMakeLists.txt

cmake_minimum_required(VERSION 3.15)

project(StereoReverb VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

# JUCE setup
include(FetchContent)
FetchContent_Declare(
  juce
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG        7.0.9
)
FetchContent_MakeAvailable(juce)

juce_add_plugin(StereoReverb
    COMPANY_NAME          "YourCompany"
    IS_SYNTH              FALSE
    NEEDS_MIDI_INPUT      FALSE
    NEEDS_MIDI_OUTPUT     FALSE
    IS_MIDI_EFFECT        FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE           SREV
    FORMATS               VST3 AU
    PRODUCT_NAME          "StereoReverb"
)

target_sources(StereoReverb PRIVATE
    PluginProcessor.cpp
    PluginEditor.cpp
    PluginProcessor.h
    PluginEditor.h
)

target_compile_definitions(StereoReverb PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
)

target_link_libraries(StereoReverb PRIVATE
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
    juce::juce_audio_utils
    juce::juce_dsp
)
```