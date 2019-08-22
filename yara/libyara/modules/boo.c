#include <yara/modules.h>
#include "deps_cortex/ssdeep/fuzzy.h"

#define MODULE_NAME boo

define_function(fuzzy_hash)
{
    YR_SCAN_CONTEXT *context = scan_context();
    YR_MEMORY_BLOCK* block = first_memory_block(context);

    // printf("\nblock : %d\n", block->size);
    const uint8_t* block_data;

    uint64_t offset = integer_argument(1);
    uint64_t length = integer_argument(2);

    printf("offset : %d\n", offset);
    printf("length : %d\n", length);

    foreach_memory_block(context->iterator, block)
    {
        block_data =  block->fetch_data(block);
        if (block_data != NULL)
        {
            printf("%d", block->size);
        }
        else
        {
            printf("\nblock is empty..\n");
        }
        
    }

}


begin_declarations;

    declare_function("fuzzy", "ii", "s", fuzzy_hash);

end_declarations;

int module_initialize(
    YR_MODULE* module)
  {
    return ERROR_SUCCESS;
  }


int module_finalize(
    YR_MODULE* module)
  {
    return ERROR_SUCCESS;
  }

int module_load(
    YR_SCAN_CONTEXT* context,
    YR_OBJECT* module_object,
    void* module_data,
    size_t module_data_size)
  {
    return ERROR_SUCCESS;
  }

int module_unload(
    YR_OBJECT* module_object)
  {
    return ERROR_SUCCESS;
  }
