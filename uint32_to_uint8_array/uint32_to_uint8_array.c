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
 * @brief Convert uint32_t into array of uint8_t.
 * @brief For example, 987654321 (0x3ade68b1) is converted into {0x3a, 0xde, 0x68, 0xb1}.
 *
 * @param uint32 Number to be converted.
 * @param uint8 Destiny array.
 */
void uint32_to_uint8_array(uint32_t uint32, uint8_t *uint8)
{
    printf("Input: %" PRIu32 " (0x%.8x)\n", uint32, uint32);
    printf("Output: {");
    for (int i = 0; i < 4; i++)
    {
        uint8[i] = (uint32 >> (24 - 8 * i)) & 0xff;
        printf("0x%.2x", uint8[i]);
        if (i != 3)
            printf(", ");
        else
            printf("}\n");
    }
}

/**
 * @brief Test.
 *
 */
void main()
{
    printf("Hello world!\n");
    uint32_t input = 987654321;
    uint8_t output[4];
    uint32_to_uint8_array(input, output);
}
