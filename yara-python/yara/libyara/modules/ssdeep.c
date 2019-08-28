#include <yara/modules.h>
#include "deps/ssdeep/fuzzy.h"

#define MODULE_NAME ssdeep

define_function(fuzzy_hash)
{
    YR_SCAN_CONTEXT *context = scan_context();
    YR_MEMORY_BLOCK* block = first_memory_block(context);
    const uint8_t* block_data;

    struct fuzzy_state *ctx = fuzzy_new();

    uint64_t offset = integer_argument(1);
    uint64_t length = integer_argument(2);

    fuzzy_set_total_input_length(ctx, length);

    char result[FUZZY_MAX_RESULT];

    foreach_memory_block(context->iterator, block)
    {
        block_data =  block->fetch_data(block);

        if (block_data != NULL)
        {
          if (length > block->size)
          {
            fuzzy_update(ctx, block_data + offset, block->size);
            length = length - (block->size - offset);
            offset = 0;
          }
          else
          {
            fuzzy_update(ctx, block_data + offset, length);
          }
        }
        else
        {
          return_integer(0);
        }
    }
    fuzzy_digest(ctx, result, 0);
    return_string(result);
}

define_function(fuzzy_cmp)
{
  YR_SCAN_CONTEXT *context = scan_context();
  YR_MEMORY_BLOCK *block = first_memory_block(context);

  char *first_fuzz = string_argument(1);
  char *second_fuzz = string_argument(2);

  int result;

  result = fuzzy_compare(first_fuzz, second_fuzz);
  return_integer(result);
}


begin_declarations;

    declare_function("hash", "ii", "s", fuzzy_hash);
    declare_function("compare", "ss","i", fuzzy_cmp);

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
