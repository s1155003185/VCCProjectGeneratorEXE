# VCCProjectGeneratorEXE

## Objective
Auto handle project update if using VCCModule. 

## Command - Add
vccproj -A
[-wsp<Workspace>] [-lib<DLL Directory>] [-int<Interface><Interface Directory>] [-src<Source Directory>]
[-SourceForceRefresh] [-SourceFullHistory] [-ExcludeExternalUnitTest]

## Command - Update
vccproj -U 
[[-wsp<Workspace>] [-lib<DLL Directory>] [-int<Interface><Interface Directory>] [-src<Source Directory>]
[-typ<Object Type File Path>] [-obj<Object Directory>] [-act<Action Type Directory>] [-err<Error Type Directory>]
[-SourceForceRefresh] [-SourceFullHistory] [-ExcludeExternalUnitTest] [-ForceUpdateVCCModel] 

### Definition
#### Mode
-A Add Mode
-U Update Mode

#### Project Workspace
##### Note <> means path. Support "path". If lib and int not stated, then it is a c++ application without dll.
-wsp Workspace, Full Path or Path relative to current directory. Default Current Directory.
-lib VCCModule c++ dll project directory. Path relative to wsp. If only dll project, no need to state. Mandatory if have UI project.
-int UI project directory. Interface can be CPP, JAVA, SWITF (only CPP support at the moment). Path relative to wsp. Link lib to UI. If UI Project already exists, then just link but create. Mandatory if have UI project.
-src Git Source Copy of VCCModule. Default Document\VCCProject

#### Enum to Object (Will generate to UI under same folder)
-typ File Path of Object Type. Path relative to -lib. Must only have one enum class. If UI has multi libraries, must different name to avoid compile error.
-obj Path (including subpath) that contains Objects. Path relative to -lib. Objects must be stated in Object Type enum class.
-act Path (including subpath) that contains Actions. Path relative to -lib.
-err Path (including subpath) that contains Errors. Path relative to -lib.

#### Control
-SourceForceRefresh Force pull Git response in -src.
-SourceFullHistory If first pull Git response, then pull whole batch history. Default 10 lastest history.
-ExcludeExternalUnitTest Ignore unit test under external. If want to customize VCCModule, recommend to keep unit test.
-ForceUpdateVCCModel Force update project from -src.

## Release Log

### 2023-05-01 First Release
- Initialization