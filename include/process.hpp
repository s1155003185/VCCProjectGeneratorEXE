#pragma once

#include <string>
#include <vector>

class Process
{
public:
    Process() {};

    void Execute(std::vector<std::wstring> &commands);
};