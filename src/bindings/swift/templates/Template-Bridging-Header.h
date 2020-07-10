// This file was autogenerated by some hot garbage in the `uniffi` crate.
// Trust me, you don't want to mess with it!

#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct RustBuffer {
    int64_t len;
    uint8_t *_Nullable data;
} RustBuffer;

{% for func in ci.iter_ffi_function_definitions() -%}
    {%- match func.return_type() -%}{%- when Some with (type_) %}{{ type_|decl_c }}{% when None %}void{% endmatch %} {{ func.name() }}(
      {%- for arg in func.arguments() %}
      {{ arg.type_()|decl_c }} {{ arg.name() }}{% if loop.last %}{% else %},{% endif %}
      {%- endfor %}
      // TODO: When we implement error handling, there will be a `*_Nonnull out_err` param here.
    );
{% endfor -%}
