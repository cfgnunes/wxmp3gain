# ===============================================================================
# String Utilities
# ===============================================================================

# -------------------------------------------------------------------------------
# Method to split a string using a delimiter.
# -------------------------------------------------------------------------------
function(split_string STRING_TO_SPLIT DELIMITER LIST_OF_SPLIT_ELEMENTS)
	message(TRACE "Splitting '${STRING_TO_SPLIT}' using delimiter '${DELIMITER}'")
	string(REPLACE ${DELIMITER} ";" SPLIT_SPRING ${STRING_TO_SPLIT})

	# Set the output variable to the split string.
	set(${LIST_OF_SPLIT_ELEMENTS} ${SPLIT_SPRING} PARENT_SCOPE)
endfunction()

# -------------------------------------------------------------------------------
# Method to split a string using a regular expression.
# -------------------------------------------------------------------------------
function(regex_split_string INPUT_STRING REGULAR_EXPRESSION OUTPUT_STRING)

		string(REGEX MATCHALL ${REGULAR_EXPRESSION} SPLIT_STRING ${INPUT_STRING})

		# Set the output variable to the value of the split string.
		set(${OUTPUT_STRING} ${SPLIT_STRING} PARENT_SCOPE)
endfunction()

# -------------------------------------------------------------------------------
# Convert an delimited input string to a UpperCamelCase string.
# -------------------------------------------------------------------------------
function(delimited_string_to_upper_camel_case DELIMITED_INPUT_STRING UPPER_CAMEL_CASE_OUTPUT DELIMITER)
	# Split the string at the delimiter.
	split_string(${DELIMITED_INPUT_STRING} ${DELIMITER} LIST_OF_SPLIT_ELEMENTS)

	# Iterate each element of the split string.
	foreach(ITERATED_ELEMENT ${LIST_OF_SPLIT_ELEMENTS})
		# Get the first character.
		string(SUBSTRING ${ITERATED_ELEMENT} 0 1 FIRST_CHARACTER)
		# Capitalize the first character.
		string(TOUPPER ${FIRST_CHARACTER} FIRST_CHARACTER_CAPITALIZED)
		
		# Get the remaining characters.
		string(SUBSTRING ${ITERATED_ELEMENT} 1 -1 REMAINING_CHARACTERS)
		# Lowercase the remaining characters.
		string(TOLOWER ${REMAINING_CHARACTERS} REMAINING_CHARACTERS_LOWERCASED)
		
		# Build up the UpperCameCase variable concatenating the capitalized first character
		# and the lowercased remaining characters.
		string(APPEND _UPPER_CAMEL_CASE_OUTPUT ${FIRST_CHARACTER_CAPITALIZED} ${REMAINING_CHARACTERS_LOWERCASED})
	endforeach()
	
	# Set the output variable to the value of the converted string.
	set(${UPPER_CAMEL_CASE_OUTPUT} ${_UPPER_CAMEL_CASE_OUTPUT} PARENT_SCOPE)
endfunction()

# -------------------------------------------------------------------------------
# Convert an delimited input string to a SCREAMING_SNAKE_CASE string.
# -------------------------------------------------------------------------------
function(delimited_string_to_screaming_snake_case DELIMITED_INPUT_STRING SCREAMING_SNAKE_CASE_OUTPUT DELIMITER)

	# Capitalize the input.
	string(TOUPPER ${DELIMITED_INPUT_STRING} CAPITALIZED_INPUT)
	
	# Replace delimiter with underscore.
	string(REPLACE ${DELIMITER} "_" _SCREAMING_SNAKE_CASE_OUTPUT ${CAPITALIZED_INPUT})
	
	# Set the output variable to the value of the converted string.
	set(${SCREAMING_SNAKE_CASE_OUTPUT} ${_SCREAMING_SNAKE_CASE_OUTPUT} PARENT_SCOPE)
endfunction()

# -------------------------------------------------------------------------------
# Lowercase the first character of the string.
# -------------------------------------------------------------------------------
function(lowercase_the_first_character INPUT_STRING OUTPUT_STRING)

		# Get the first character.
		string(SUBSTRING ${INPUT_STRING} 0 1 FIRST_CHARACTER)
		# Lowercase the first character.
		string(TOLOWER ${FIRST_CHARACTER} FIRST_CHARACTER_LOWERED)
		
		# Get the remaining characters.
		string(SUBSTRING ${INPUT_STRING} 1 -1 REMAINING_CHARACTERS)
		
		# Build up the OUTPUT_STRING variable concatenating the lowered first character
		# and the remaining characters.
		string(APPEND _OUTPUT_STRING ${FIRST_CHARACTER_LOWERED} ${REMAINING_CHARACTERS})

		# Set the output variable to the value of the converted string.
		set(${OUTPUT_STRING} ${_OUTPUT_STRING} PARENT_SCOPE)
endfunction()

# -------------------------------------------------------------------------------
# Insert space before upper case character.
# Can be used to convert 'UpperCamelCase' to 'Space Separated'.
# -------------------------------------------------------------------------------
function(insert_space_before_upper_case INPUT_STRING OUTPUT_STRING)

		# Use regular expression to split the string at the beginning of a capital letter.
		regex_split_string(${INPUT_STRING} "[A-Z0-9]+[a-z0-9]*" SPLIT_STRING)

		# Convert to whitespace seperated string.
		string(REPLACE ";" " " WHITE_SPACE_SEPERATED "${SPLIT_STRING}")

		# Set the output variable to the value of the converted string.
		set(${OUTPUT_STRING} ${WHITE_SPACE_SEPERATED} PARENT_SCOPE)
endfunction()


