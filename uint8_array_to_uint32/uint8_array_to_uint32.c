/*

Copyright [2023] [Henrique Sander Lourenço]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/**
 * @brief Convert array of uint8_t into uint32_t.
 * @brief For example, {0x3a, 0xde, 0x68, 0xb1} is converted into 987654321 (0x3ade68b1).
 *
 * @param uint8 Source array.
 * @return uint32_t Converted number.
 */
uint32_t uint8_array_to_uint32(uint8_t *uint8)
{
    printf("Input: {");
    uint32_t uint32 = 0;
    for (int i = 0; i < 4; i++)
    {
        printf("0x%.2x", uint8[i]);
        if (i != 3)
            printf(", ");
        else
            printf("}\n");
        uint32 += ((uint8[i] << (8 * (3 - i))) & (0x000000ff << (8 * (3 - i))));
    }
    printf("Output: %" PRIu32 "\n", uint32);
    return uint32;
}

/**
 * @brief Test.
 *
 */
void main()
{
    printf("Hello world!\n");
    uint8_t input[4] = {0x3a, 0xde, 0x68, 0xb1};
    uint32_t output = uint8_array_to_uint32(input);
    printf("Output (confirmation): %" PRIu32 "\n", output);
}
