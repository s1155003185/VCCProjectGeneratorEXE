#include "process.hpp"

#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string wstr2str(const std::wstring &wstr)
{
    if (wstr.empty())
        return "";
    int len = wstr.size() * 4 + 1;
    std::unique_ptr<char[]> p(new char[len]);
    wcstombs(p.get(), wstr.c_str(), len);
    std::string str(p.get());
    return str;
}

void Process::_ParseCommand(std::vector<std::wstring> &commands)
{
    // skip first argument
    for (size_t i = 1; i < commands.size(); i++) {
        std::wstring arg = commands[i];
        if (i == 1) {
            if (arg == L"-v") {
                std::wcout << this->_Version << std::endl;
                return;
            } else if (arg == L"-A")
                this->_Mode = ModeType::Add;
            else if (arg == L"-U")
                this->_Mode = ModeType::Update;
            else
                throw std::runtime_error("Unknown Mode " + wstr2str(arg));
            continue;
        }

        // VCC Git Source
        if (arg == L"-s") {
            this->_VccLocalSource = commands[i + 1];
        } 
        
        // workspace
        else if (arg == L"-w") {
            this->_Workspace = commands[i + 1];
        } else if (arg == L"-l") {
            this->_DLLDirectory = commands[i + 1];
        } else if (arg == L"-i=VCC") {
            this->_InterfaceType = InterfaceType::VCC;
        } else if (arg == L"-i=CPP") {
            this->_InterfaceType = InterfaceType::CPP;
        } else if (arg == L"-i=JAVA") {
            this->_InterfaceType = InterfaceType::JAVA;
        } else if (arg == L"-i=SWIFT") {
            this->_InterfaceType = InterfaceType::SWIFT;
        }
        
        // project
        else if (arg == L"-type") {
            this->_ObjectTypeFilePath = commands[i + 1];
        } else if (arg == L"-obj") {
            this->_ObjectPropertyTypeDirectory = commands[i + 1];
        } else if (arg == L"-act") {
            this->_ActionTypeDirectory = commands[i + 1];
        } else if (arg == L"-err") {
            this->_ErrorTypeDirectory = commands[i + 1];
        }
        
        // option
        else if (arg == L"-SourceForceRefresh") {
            this->_IsSourceForceRefresh = true;
        } else if (arg == L"-SourceFullHistory") {
            this->_IsSourceFullHistrory = true;
        } else if (arg == L"-ExcludeExternalUnitTest") {
            this->_IsExcludeExternalUnitTest = true;
        } else if (arg == L"-ForceUpdateVCCModel") {
            this->_ForceUpdateVCCModel = true;
        }
    }
}

void Process::Execute(std::vector<std::wstring> &commands)
{
    if (commands.size() < 2)
        return;
    this->_ParseCommand(commands);
    // Execute
}