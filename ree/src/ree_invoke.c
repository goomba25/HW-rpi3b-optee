#include "ree_invoke.h"
#include <tee_client_api.h>

#include "ree_log.h"

static TEEC_Context g_taContext = {
    0,
};

static TEEC_Session g_taSession = {
    0,
};

uint32_t ivk_OpenTa(void)
{
    uint32_t result = 0U;
    TEEC_UUID uuid = TA_UUID;

    LogDebug("Function Call ivk_OpenTa");

    result = TEEC_InitializeContext(NULL, &g_taContext);
    if (result != TEEC_SUCCESS)
    {
        LogError("Failed to TEEC_InitializeContext (%08x)", result);
        TEEC_FinalizeContext(&g_taContext);
    }
    else
    {
        result = TEEC_OpenSession(&g_taContext, &g_taSession, &uuid, TEEC_LOGIN_USER, NULL, NULL, NULL);
        if (result != TEEC_SUCCESS)
        {
            LogError("Failed to TEEC_OpenSession (%08x)", result);
        }
    }

    return result;
}

void ivk_CloseTa(void)
{
    LogDebug("Function Call ivk_CloseTa");
    TEEC_CloseSession(&g_taSession);
    TEEC_FinalizeContext(&g_taContext);
}

uint32_t ivk_RunOperationTa(uint32_t cmdId,
                            void *src1,
                            uint32_t srcLength1,
                            void *src2,
                            uint32_t srcLength2,
                            void *src3,
                            uint32_t srcLength3,
                            void *src4,
                            uint32_t srcLength4)
{
    uint32_t result = 0U;
    uint32_t returnOrigin = 0U;
    TEEC_Operation teeOper = {0U};
    uint8_t tmpBuffer[1] = {0};
    uint32_t tmpLength[1] = {0};

    teeOper.paramTypes = (uint32_t)(TEEC_MEMREF_TEMP_INPUT | (TEEC_MEMREF_TEMP_OUTPUT << 4U) |
                                    (TEEC_MEMREF_TEMP_OUTPUT << 8U) | (TEEC_MEMREF_TEMP_OUTPUT << 12U));

    if (src1 == NULL)
    {
        src1 = tmpBuffer;
        srcLength1 = 0U;
    }
    teeOper.params[0].tmpref.buffer = src1;
    teeOper.params[0].tmpref.size = srcLength1;

    if (src2 == NULL)
    {
        src2 = tmpBuffer;
        srcLength2 = 0U;
    }
    teeOper.params[1].tmpref.buffer = src2;
    teeOper.params[1].tmpref.size = srcLength2;

    if (src3 == NULL)
    {
        src3 = tmpBuffer;
        srcLength3 = 0U;
    }
    teeOper.params[2].tmpref.buffer = src3;
    teeOper.params[2].tmpref.size = srcLength3;

    if (src4 == NULL)
    {
        src4 = tmpBuffer;
        srcLength4 = 0U;
    }
    teeOper.params[3].tmpref.buffer = src4;
    teeOper.params[3].tmpref.size = srcLength4;

    result = TEEC_InvokeCommand(&g_taSession, cmdId, &teeOper, &returnOrigin);
    if (result != TEEC_SUCCESS)
    {
        LogError("Failed to TEEC_InvokeCommand (%08x:%08x)", result, returnOrigin);
    }

    return result;
}