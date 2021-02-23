#ifndef CUSTOM_HPP
#define CUSTOM_HPP 1

#define PROGRAMMING_LANGUAGE_NAME "proglang"
#define PROGRAMMING_LANGUAGE_EXTENSION "plg"
#define PROGRAMMING_LANGUAGE_VERSION "1.0"
#define PROGRAMMING_LANGUAGE_AUTHOR ""

#define COMMENT "%" // How comments should look
#define LINE_TERM ";" // What should every line end with? Set it to "" if you don't want a line terminator
#define PRINT "print " // What should the user enter to print a certain value, example PRINT "Hello, World!"

/* FUNCTIONS */
#define FUNC_COMMAND true // Should function exist?
#define FUNC_DEF "f " // Must be followed by a space
#define FUNC_LEFT_WING "("
#define FUNC_RIGHT_WING ")"
#define FUNC_LEFT_OPEN_WING "{"
#define FUNC_RIGHT_CLOSE_WING "}"

/* Variables */
#define VAR_COMMAND true // Should variables exist?
#define VAR_DEF "v "
#define VAR_ASS_OP "=" // Example VAR_DEF A = 10 compared to VAR_DEF A 10
#define VAR_VALUE "$" // What must the user append to tell you that he/she wants to use the value of a variable?

/* Const variables */
#define CONST_COMMAND true // Should const values exist?
#define CONST_DEF "c " // The following is the exact same as for the variables above
#define CONST_ASS_OP "="
#define CONST_VALUE "$"

/* If/else-statements */
#define IF_COMMAND true
#define IF_DEF "if" // How should an if statement look?
#define IF_LEFT_WING "("
#define IF_RIGHT_WING ")"
#define IF_LEFT_OPEN_WING "{"
#define IF_RIGHT_CLOSE_WING "}"
#define ELSE_IF_COMMAND true // Should an else if command be allowed?
#define ELSE_IF_DEF "elif" // How should an else if look?
#define ELSE_COMMAND true
#define ELSE_DEF "else" // How should an else command look?

/* goto */
#define GOTO_COMMAND true // Should an goto exist?
#define GOTO_DEF "goto" // How should a goto look like?

/* LIVE SESSION */
#define LIVE_SESSION_INDI ":: " // Should be followed by a space

// Predefined functions that the end-user can enter when running the live session
#define LIVE_SESSION_HELP_COMMAND true  // Should the command be enabled/disabled?
#define LIVE_SESSION_HISTORY_COMMAND true // Should the command be enabled/disabled?

#define LIVE_SESSION_HELP "help" // Prints the help screen
#define LIVE_SESSION_QUIT "quit" // Ends the program
#define LIVE_SESSION_WRITE "write" // Writes everything that has been entered into the live session to the disk
#define LIVE_SESSION_HISTORY "history" // Prints the n latest entered values
#define LIVE_SESSION_ABOUT "about" // Prints some information about the program
#define LIVE_SESSION_HISTORY_MAX 10 // How many lines should the history function print?

#endif
