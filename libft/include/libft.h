/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:02:22 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/23 15:31:05 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

//char classification

/**
 * @brief tests if a given character, in the current locale, can be represented
 * as a valid 7–bit US-ASCII character.
 *
 * @param c this is the character to be checked.
 * @return int, returns nonzero if c, in the current locale, can be represented
 * as a character in the 7–bit US-ASCII character set. Otherwise, it returns 0.
 */
int				ft_isascii(int c);

/**
 * @brief checks whether a character is a printable character or not.
 *
 * @param c this is the character to be checked
 * @return int, if the character passed is a printable character, it returns
 * non-zero integer, if not it returns 0.
 */
int				ft_isprint(int c);

/**
 * @brief checks if the passed character is alphabetic.
 *
 * @param c this is the character to be checked
 * @return int, this function returns non-zero value if c is alphabetic,
 * else it returns 0.
 */
int				ft_isalpha(int c);

/**
 * @brief checks if the passed character is a decimal digit character -
 * 0 1 2 3 4 5 6 7 8 9.
 *
 * @param c the character to be checked.
 * @return int, this function returns non-zero value if c is a digit, else it
 * returns 0.
 */
int				ft_isdigit(int c);

/**
 * @brief checks if the passed string contains only numeric characters.
 *
 * @param str the string to be checked.
 * @return int this function returns non-zero value if str contains only numeric
 * characters, else it returns 0.
 */
int				ft_isnumber(char *str);

/**
 * @brief checks if the passed string is numeric.
 *
 * @param c the string to be checked.
 * @return int, this function returns non-zero value if c is a digit, else it
 * returns 0.
 */
int				ft_str_isdigit(char *str);

/**
 * @brief The ft_isblank() function tests for a space or tab character.
**	This includes the following: space ' ' and tab '\t'
**	The value of the argument must be representable as an unsigned char
**	or the value of EOF.
 *
 * @param c character to be tested
 * @return int returns zero if the character tests false and returns non-zero
 *  if the character tests true.
 */
int				ft_isblank(char c);

/**
 * @brief checks if the passed character is alphanumeric.
 *
 * @param c the character to be checked.
 * @return int, returns non-zero value if c is a digit or a letter, else it
 * returns 0.
 */
int				ft_isalnum(int c);

/**
 * @brief ft_islong is a function that checks if the passed string is a long
 * number.
 *
 * @param str the string to be checked.
 * @return int this function returns non-zero value if nptr is a long number,
 * else it returns 0.
 */
int				ft_islong(const char *str);

/**
 * @brief Checks if there's still data to be read from data source.
 *
 * @param input data source
 * @return int 1 if EOF was reached, 0 if there's data to be read.
 */
int				ft_is_eof(char *str);

//char manipulation

/**
 * @brief converts a given letter to lowercase.
 *
 * @param c this is the letter to be converted to lowercase.
 * @return int, returns lowercase equivalent to c, if such value exists, else c
 * remains unchanged. The value is returned as an int that can be implicitly
 * casted to char.
 */
int				ft_tolower(int c);

/**
 * @brief
 *
 * @param c this is the letter to be converted to uppercase.
 * @return int, returns uppercase equivalent to c, if such value exists, else c
 * remains unchanged. The value is returned as an int value that can be
 * implicitly casted to char.
 */
int				ft_toupper(int c);

//string examination

/**
 * @brief computes the length of the string str up to, but not including
 * the terminating null character.
 *
 * @param str this is the string whose length is to be found.
 * @return size_t this function returns the length of string.
 */
size_t			ft_strlen(const char *str);

/**
 * @brief searches for first occurrence of "c" in the string *str
 *
 * @param str the string
 * @param c character to be checked
 * @return char*, a pointer to the first occurrence of character c in *str or
 * NULL if the character is not found. The terminating null byte is considered
 * part of the string.
 */
char			*ft_strchr(const char *str, int c);

/**
 * @brief searches for the last occurrence of the character c (an unsigned char)
 *  in the string pointed to, by the argument str.
 *
 * @param str this is the C string.
 * @param c this is the character to be located. It is passed as its int
 * promotion, but it is internally converted back to char.
 * @return char*, function returns a pointer to the last occurrence of character
 *  in str. If the value is not found, the function returns a null pointer.
 */
char			*ft_strrchr(char *str, int c);

/**
 * @brief locates the first occurrence of the null-terminated string pointed by
 * little in string pointed by big. Characters that appear after a '\0' or len
 * are not searched.
 *
 * @param big the main C string to be scanned.
 * @param little the small string to be searched with-in big string.
 * @param len maximum number of characters to be searched.
 * @return if little is an empty string, big is returned, if little occurs
 * nowhere in big, NULL is returned; otherwise a pointer to the first character
 * of the first occurrence of little is returned.
 */
char			*ft_strnstr(char *big, char *little, size_t len);

/**
 * @brief compares at most the first n bytes of str1 and str2.
 *
 * @param s1 this is the first string to be compared.
 * @param s2 this is the second string to be compared.
 * @param n the first n bytes of to be compared
 * @return if Return value < 0 then it indicates str1 is less than str2. If
 * Return value > 0 then it indicates str2 is less than str1. If Return
 * value = 0 then it indicates str1 is equal to str2.
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief compares str1 and str2.
 *
 * @param s1 this is the first string to be compared.
 * @param s2 this is the second string to be compared.
 * @return if Return value < 0 then it indicates str1 is less than str2. If
 * Return value > 0 then it indicates str2 is less than str1. If Return
 * value = 0 then it indicates str1 is equal to str2.
 */
int				ft_strcmp(const char *s1, const char *s2);

//string manipulation

/**
 * @brief  copies up to size - 1 characters from the NUL-terminated string src
 * to dst, NUL-terminating the result.
 *
 * @param dest destination string
 * @param src source string
 * @param size (dest) nothing will be written beyond dest + size - 1.
 * @return size_t, the total length of the string it tried to create (entire
 * source string)
 */
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief appends the NUL-terminated string src to the end of dest. It will
 * append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
 *
 * @param dest first string
 * @param src the string to be appended
 * @param n nothing will be written beyond dst + size - 1.
 * @return size_t, the total lenght of the string it tried to create.
 */
size_t			ft_strlcat(char *dest, char *src, size_t n);

/**
 * @brief returns a pointer to a new string duplicated of the string s. Memory
 *for the new string is obtained with malloc
 *
 * @param s1 the string which will be duplicated
 * @return char*, a pointer to the new string
 */
char			*ft_strdup(const char *s1);

/**
 * @brief allocates sufficient memory for a copy of the n first elements of the
 * string s1, does the copy, and returns a pointer to it.
 * @param s1 The string to duplicate.
 * @param lenght The size of the new string.
 * @return The strdup() function returns the pointer to the copy of s1.
 */
char			*ft_strndup(const char *s1, size_t length);

//conversion (to int)
/**
 * @brief converts the initial portion of the string pointed to by str to int.
 *
 * @param str string to be converted
 * @return int the converted value
 */
int				ft_atoi(const char *str);

/**
 * @brief This utility function converts the initial portion of the string
 * pointed to by str to its int representation considering a given base.
 * @param str The string to convert to integer.
 * @param base The base in which to convert the string from, all lowercased.
 * @return int Returns the converted int representation.
 */
int				ft_atoi_base(char *str, char *base);

/**
 * @brief converts string to long
 *
 * @param str string to operate on
 * @return long converted long
 */
long long int	ft_atol(const char *str);

//memory manipulation

/**
 * @brief fill memory with a constant byte
 *
 * @param s this is a pointer to the block of memory to fill.
 * @param c the value to be set, the value is passed as an int, but the
 * function fills the block of memory using the unsigned char conversion of
 * this value.
 * @param n this is the number of bytes to be set to the value.
 * @return void*, this function returns a pointer to the memory area str.
 */
void			*ft_memset(void *s, int c, size_t n);

/**
 * @brief copies n bytes, each with a value of zero, into string s.

 *
 * @param s points to a buffer that zeros are copied into.
 * @param n the number of zeros to be copied into the buffer.
 */
void			ft_bzero(void *s, size_t n);

/**
 * @brief copies n bytes from memory area src to memory area dest. The memory
 * areas must not overlap. Use memmove if the memory areas do overlap.
 *
 * @param dest a pointer to the destination array where the content
 * is to be copied, type-casted to a pointer of type void*.
 * @param src this is pointer to the source of data to be copied,
 * type-casted to a pointer of type void*.
 * @param n this is the number of bytes to be copied.
 * @return void* this function returns a pointer to destination.
 */
void			*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief
 *
 * @param dest a pointer to the destination array where the content is to be
 * copied, type-casted to a pointer of type void*.
 * @param src a pointer to the source of data to be copied, type-casted to a
 * pointer of type void*.
 * @param len the number of bytes to be copied.
 * @return void* a pointer to dest.
 */
void			*ft_memmove(void *dest, const void *src, size_t len);

//memory examination

/**
 * @brief
 *
 * @param str the pointer to the block of memory where the search is performed.
 * @param c the value to be passed as an int, but the function performs a byte
 * per byte search using the unsigned char conversion of this value.
 * @param n the number of bytes to be analyzed.
 * @return void*, a pointer to the matching byte or NULL if the character does
 * not occur in the given memory area.
 */
void			*ft_memchr(const void *str, int c, size_t n);

/**
 * @brief
 *
 * @param s1 this is the pointer to a block of memory.
 * @param s2 this is the pointer to a block of memory.
 * @param n this is the number of bytes to be compared.
 * @return int: if < 0 then it indicates s1 is less than s2, if > 0 then it
 * indicates s2 is less than s1, if = 0 then it indicates s1 is equal to s2.

 */
int				ft_memcmp(const void *s1, const void *s2, size_t n);

//dynamic manipulation

/**
 * @brief
 *
 * @param number the number of elements, if zero (0), a unique pointer to the
 * heap is returned.
 * @param size the size of each element, if zero (0), a unique pointer to the
 * heap is returned.
 * @return void* if successful, it returns a pointer to space suitably aligned
 * for storage of any type of object, if there is no available memory, it
 * returns a null pointer.
 */
void			*ft_calloc(size_t number, size_t size);

//additionals

/**
 * @brief allocates (with malloc(3)) and returns a stringrepresenting the
 * integer received as an argument. Negative numbers must be handled.
 *
 * @param n, the integer to convert.
 * @return char*,the string representing the integer. NULL if allocation fails.
 */

char			*ft_itoa(int n);

/**
 * @brief Outputs the character ’c’.
 *
 * @param c the character to output.
 */
void			ft_putchar(char c);

/**
 * @brief Outputs the character ’c’ to the given filedeshellor.
 *
 * @param c the character to output.
 * @param fd the file deshellor on which to write. in C, stdin, stdout, and
 * stderr are FILE*, which UNIX respectively map to file deshellors 0, 1 and 2.
 */

void			ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's'.
 *
 * @param s the string to output.
 */
void			ft_putstr(char *str);

/**
 * @brief Outputs the string 's' to the given filedeshellor.
 *
 * @param s the string to output.
 * @param fd the file deshellor on which to write. in C, stdin, stdout, and
 * stderr are FILE*, which UNIX respectively map to file deshellors 0, 1 and 2.
 */
void			ft_putstr_fd(char *s, int fd);

/**
 * @brief outputs the string ’s’ to the given filedeshellor, followed by a
 * newline
 *
 * @param s the string to output.
 * @param fd the file deshellor on which to write. in C, stdin, stdout, and
 * stderr are FILE*, which UNIX respectively map to file deshellors 0, 1 and 2.
 */
void			ft_putendl_fd(const char *s, int fd);

/**
 * @brief outputs the integer 'n'
 *
 * @param n the integer to output
 */
void			ft_putnbr(int n);

/**
 * @brief outputs the integer 'n' to the given filedeshellor.
 *
 * @param n the integer to output
 * @param fd the file deshellor on which to write. in C, stdin, stdout, and
 * stderr are FILE*, which UNIX respectively map to file deshellors 0, 1 and 2.
 */

void			ft_putnbr_fd(int n, int fd);

/**
 * @brief applies the function f to each character of the string passed as
 * argument, and passing its index as first argument. Each character is passed
 * by address to f to be modified if necessary.
 *
 * @param s the string on which to iterate
 * @param f the function to apply to each character
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief allocates (with malloc) and returns a substring from the string 's'.
 * The substring begins at index 'start' and is of maximum size ’len’.
 *
 * @param s the string from which to create the substring.
 * @param start the start index of the substring in the string 's'.
 * @param len the maximum length of the substring.
 * @return char*, the substring. NULL if the allocation fails.
 */
char			*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc) and returns a new string, which is the result
 * of the concatenation of ’s1’ and ’s2’.
 *
 * @param s1 the prefix string.
 * @param s2 the suffix string.
 * @return char* the new string. NULL if the allocation fails
 */
char			*ft_strjoin(const char *s1, const char *s2);

/**
 * @brief This function is similar to strjoin, but it frees the memory of the
 * allocated strings before returning the result of the concatenation to
 * prevent memory leaks.
 *
 * @param s1 the prefix string.
 * @param s2 the suffix string.
 * @return char* the new string. NULL if the allocation fails
 */
char			*ft_strjoin_free(char *s1, char *s2);

/**
 * @brief a variadic function that allows the user to concatenate multiple
 * strings they may want. The first argument must be the number of arguments
 * to be passed, followed by the strings to concatenate. The user must pass the
 * exact number of arguments, otherwise the function will most likely segfault.
 *
 * @param number number of strings
 * @param ... variadic number of strings to concatenate
 * @return char* concatenated string.
 */
char			*ft_strnjoin(int number, ...);

/**
 * @brief allocates (with malloc) and returns a copy of 's1' with the characters
 *  specified in ’set’ removed from the beginning and the end of the string
 *
 * @param s1 the string to be trimmed
 * @param set the reference set of characters to trim
 * @return char*, the trimmed string.  NULL if the allocation fails.
 */
char			*ft_strtrim(const char *s1, const char *set);

/**
 * @brief allocates (with malloc) and returns an array of strings obtained by
 * splitting 's' using the character ’c’ as a delimiter. The array must be
 * ended by a NULL pointer.
 *
 * @param s the string to be split
 * @param c the delimiter character
 * @return char**, the array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char			**ft_split(const char *s, char c);

/**
 * @brief This function is similar to the ft_split function, but it take as a
 * parameter more than one character as a delimiter.
 *
 * @param s the string to be split
 * @param charset the delimiter characters
 * @return char** the array of new strings resulting from the split.
 */
char			**ft_split_charset(char *s, char *charset);

/**
 * @brief applies the function ’f’ to each character of the string 's' to
 * create a new string (with malloc) resulting from successive applications of
 * 'f'.
 *
 * @param s the string on which to iterate.
 * @param f the function to apply to each character.
 * @return char* the string created from the successive applications of 'f'.
 * Returns NULL if the allocation fails.
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Adds the character ’c’ to the end of the string ’str’.
 *
 * @param str the string to which to add the character.
 * @param c the character to add.
 * @return char* the string ’str’ with the character ’c’ added to the end.
 */
char			*ft_add_char_to_str(char *str, char c);

/**
 * @brief Deletes and frees the given node and every
	successor of that node, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to
	NULL.
 *
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
	the content of the node.
 */
void			ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed.
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete
	the content.
 */
void			ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.
 *
 * @param lst  The address of a pointer to a node.
 * @param f The address of the function used to iterate on
the list.
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Adds the node ’new’ at the end of the list.
 *
 * @param lst  The address of a pointer to the first link of
	a list.
 * @param new  The address of a pointer to the node to be
	added to the list.
 */
void			ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 *
 * @param lst  The address of a pointer to the first link of
	a list.
 * @param new  The address of a pointer to the node to be
	added to the list.
 */
void			ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Returns the last node of the list.
 *
 * @param lst  The beginning of the list.
 * @return t_list* Last node of the list
 */
t_list			*ft_lstlast(t_list *lst);

/**
 * @brief Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.
 *
 * @param lst  The address of a pointer to a node.
 * @param f The address of the function used to iterate on
	the list.
 * @param del The address of the function used to delete
	the content of a node if needed.
 * @return t_list* The new list.
	NULL if the allocation fails.
 */
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with
	the value of the parameter ’content’. The variable
	’next’ is initialized to NULL.
 *
 * @param content The content to create the node with.
 * @return t_list* The new node
 */
t_list			*ft_lstnew(void *content);

/**
 * @brief Counts the number of nodes in a list.
 *
 * @param lst The beginning of the list.
 * @return int The length of the list
 */
int				ft_lstsize(t_list *lst);

#endif
