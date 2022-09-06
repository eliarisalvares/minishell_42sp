NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar -rcs
RM			= rm -rf

SRCS_PATH = ./src/
OBJS_PATH = ./libft_objects/

INCLUDES	= ./include/libft.h
SOURCES		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_atoi_base.c ft_strnjoin.c ft_atol.c ft_isblank.c\
			ft_strndup.c ft_strisalnum.c ft_putchar.c ft_isnumber.c\
			ft_str_isdigit.c ft_putnbr.c ft_split_charset.c ft_is_eof.c\
			ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c\
			ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_islong.c ft_lstlast.c\

VPATH = $(SRCS_PATH)

OBJECTS		= $(addprefix $(OBJS_PATH), $(notdir $(SOURCES:.c=.o)))

$(OBJS_PATH)%.o: %.c
				mkdir -p $(OBJS_PATH)
				$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJECTS) $(INCLUDES)
			$(AR)	$(NAME) $(OBJECTS)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJECTS)
			$(RM) $(OBJS_PATH)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(OBJS_PATH)

re:			fclean all

.PHONY:		all clean fclean re
