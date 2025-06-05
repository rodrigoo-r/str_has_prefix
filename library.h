/*
 * This code is distributed under the terms of the GNU General Public License.
 * For more information, please refer to the LICENSE file in the root directory.
 * -------------------------------------------------
 * Copyright (C) 2025 Rodrigo R.
 * This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
 * This is free software, and you are welcome to redistribute it
 * under certain conditions; type `show c' for details.
*/


#ifndef FLUENT_LIBC_STR_HAS_PREFIX_LIBRARY_H
#define FLUENT_LIBC_STR_HAS_PREFIX_LIBRARY_H

// ============= FLUENT LIB C =============
// String Prefix Check Utility
// ----------------------------------------
// Provides a fast, zero-allocation function to check if a string starts with a prefix.
//
// API:
//   • str_has_prefix(str, prefix) – returns TRUE if `str` starts with `prefix`, else FALSE.
//
// Notes:
//   - NULL inputs return FALSE (safe to call with unchecked strings).
//   - Comparison is byte-wise and case-sensitive.
//
// Performance:
//   - O(n) where n = length of prefix.
//   - Early-exit on first mismatch (no memory allocation).
//
// Dependencies:
//   - `types.h` and `std_bool.h` from Fluent Lib C (for `bool` and `TRUE`/`FALSE`).
//
// Example:
// ----------------------------------------
//   if (str_has_prefix("https://example.com", "https://")) {
//       printf("It's secure\n");
//   }
//
//   if (!str_has_prefix(input, "--")) {
//       puts("Expected flag prefix '--' not found");
//   }

// ============= INCLUDES =============
#ifndef FLUENT_LIBC_RELEASE
#    include <types.h> // fluent_libc
#    include <std_bool.h> // fluent_libc
#else
#    include <fluent/types/types.h> // fluent_libc
#    include <fluent/std_bool/std_bool.h> // fluent_libc
#endif

/**
 * Checks if the given string `str` starts with the specified `prefix`.
 *
 * \param str     The string to check.
 * \param prefix  The prefix to look for at the start of `str`.
 * \return        TRUE if `str` starts with `prefix`, FALSE otherwise.
 *
 * Returns FALSE if either `str` or `prefix` is NULL.
 */
static inline bool str_has_prefix(
    const char *str,
    const char *prefix
)
{
    // Check if the string or prefix is NULL
    if (!str || !prefix)
    {
        return FALSE; // Return false if either is NULL
    }

    // Iterate over the characters of the prefix
    for (size_t i = 0; prefix[i] != '\0'; i++)
    {
        // If the current character in the string does not match the prefix
        if (str[i] != prefix[i])
        {
            return FALSE; // Return false
        }
    }

    // If we reached here, the prefix matches the start of the string
    return TRUE; // Return true
}

#endif //FLUENT_LIBC_STR_HAS_PREFIX_LIBRARY_H