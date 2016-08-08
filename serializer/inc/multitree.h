// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef MULTITREE_H
#define MULTITREE_H

#include "azure_c_shared_utility/strings.h"
#include "azure_c_shared_utility/macro_utils.h"

#ifdef __cplusplus
#include <cstddef>
extern "C"
{
#else
#include <stddef.h>
#endif

typedef struct MULTITREE_HANDLE_DATA_TAG* MULTITREE_HANDLE;

#define MULTITREE_RESULT_VALUES           \
    MULTITREE_OK,                         \
    MULTITREE_INVALID_ARG,                \
    MULTITREE_ALREADY_HAS_A_VALUE,        \
    MULTITREE_EMPTY_CHILD_NAME,           \
    MULTITREE_EMPTY_VALUE,                \
    MULTITREE_OUT_OF_RANGE_INDEX,         \
    MULTITREE_ERROR,                      \
    MULTITREE_CHILD_NOT_FOUND             \

DEFINE_ENUM(MULTITREE_RESULT, MULTITREE_RESULT_VALUES);

typedef void (*MULTITREE_FREE_FUNCTION)(void* value);
typedef int (*MULTITREE_CLONE_FUNCTION)(void** destination, const void* source);

extern MULTITREE_HANDLE MultiTree_Create(MULTITREE_CLONE_FUNCTION cloneFunction, MULTITREE_FREE_FUNCTION freeFunction);
extern MULTITREE_RESULT MultiTree_AddLeaf(MULTITREE_HANDLE treeHandle, const char* destinationPath, const void* value);
extern MULTITREE_RESULT MultiTree_AddChild(MULTITREE_HANDLE treeHandle, const char* childName, MULTITREE_HANDLE* childHandle);
extern MULTITREE_RESULT MultiTree_GetChildCount(MULTITREE_HANDLE treeHandle, size_t* count);
extern MULTITREE_RESULT MultiTree_GetChild(MULTITREE_HANDLE treeHandle, size_t index, MULTITREE_HANDLE* childHandle);
extern MULTITREE_RESULT MultiTree_GetChildByName(MULTITREE_HANDLE treeHandle, const char* childName, MULTITREE_HANDLE* childHandle);
extern MULTITREE_RESULT MultiTree_GetName(MULTITREE_HANDLE treeHandle, STRING_HANDLE destination);
extern MULTITREE_RESULT MultiTree_GetValue(MULTITREE_HANDLE treeHandle, const void** destination);
extern MULTITREE_RESULT MultiTree_GetLeafValue(MULTITREE_HANDLE treeHandle, const char* leafPath, const void** destination);
extern MULTITREE_RESULT MultiTree_SetValue(MULTITREE_HANDLE treeHandle, void* value);
extern void MultiTree_Destroy(MULTITREE_HANDLE treeHandle);

#ifdef __cplusplus
}
#endif

#endif