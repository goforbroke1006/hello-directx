//
// Created by GOFORBROKE on 10.09.2020.
//

#ifndef INIT_DX_UTILS_H
#define INIT_DX_UTILS_H

#include <windows.h>
#include <fstream>
#include <d3dcommon.h>
#include <d3dcompiler.h>

void WINAPI D3DCompileFromFile(
        const char *filename,
        const D3D_SHADER_MACRO *defines,
        ID3DInclude *include,
        const char *entrypoint,
        const char *target,
        UINT sflags, UINT eflags,
        ID3DBlob **shader,
        ID3DBlob **error_messages
) {
    SIZE_T data_size;
    char *buffer;

    std::ifstream infile;
    infile.open(filename, std::ios::binary);
    infile.seekg(0, std::ios::end);
    data_size = infile.tellg();
    infile.seekg(0, std::ios::beg);
    buffer = new char[data_size];
    infile.read(buffer, data_size);
    infile.close();

    D3DCompile(
            buffer, data_size, filename,
            defines, include, entrypoint,
            target, sflags, eflags, shader, error_messages
    );
}

#endif //INIT_DX_UTILS_H
