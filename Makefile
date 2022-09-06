# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 18:39:42 by elraira-          #+#    #+#              #
#    Updated: 2022/09/01 03:15:34 by elraira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[32m
BLUE = \033[34m
YELLOW = \e[0;33m
RESET = \033[0m

NAME			= minishell
LIBFT			= libft.a

CC 				= gcc
CF 				= -Wall -Wextra -Werror
CINC 			= -I $(INCLUDE_PATH)
CREAD			= -lreadline

LIBFT_PATH 		= ./libft/
SRCS_PATH 		= ./src/
OBJS_PATH		= ./minishell_objects/
INCLUDE_PATH 	= ./include/

SRCS			= main.c exit_builtin.c pwd_builtin.c export_builtin.c\
				export_utils.c cd_builtin.c echo_builtin.c env_builtin.c\
				unset_builtin.c is_minishell_command.c free_command_struct.c\
				free_parser_struct.c free_tokens.c return_error.c free_envp.c\
				init_hashtable_struct.c free_hashtable.c send_env_to_hashtable.c\
				free_path.c free_execution_list.c create_execution_envp.c\
				insert_pair.c hash_function.c get_location.c key_lookup.c\
				init_parser_struct.c is_valid_token.c set_command_endpoints.c\
				send_to_execution_in_child.c send_to_execution_in_parent.c\
				define_token_type.c check_bash_grammar.c is_valid_pipe.c\
				is_forked_command.c is_valid_redirection.c convert_to_array.c\
				is_closed_quotation_mark.c fill_command_table.c wait_pids.c\
				command_list_utils.c token_list_utils.c command_execution.c\
				start_expansion.c expand_parameter.c free_pairs.c\
				quotes_utils.c start_execution.c open_necessary_pipes.c\
				define_redirection_fds.c child_execution.c has_matching_quote.c\
				close_all_file_descriptors.c get_command_path.c is_expandable.c\
				heredoc.c close_single_file_descriptor.c token_list.c\
				get_pair_value.c get_pair_key.c free_minishell.c\
				split_path.c check_access.c child_signals.c is_redirection.c\
				parent_signals.c heredoc_signals.c start_tokenization_process.c\
				is_valid_file_descriptor.c open_redirection_files.c\
				expand_dollar_and_quotes.c expand_redirections.c\
				create_execution_array.c free_expansion_array.c heredoc_error.c\
				cd_utils.c command_path_error.c free_export_pwd_oldpwd.c\

VPATH 			:= $(SRCS_PATH)\
				$(SRCS_PATH)builtins\
				$(SRCS_PATH)command_struct\
				$(SRCS_PATH)hashtable\
				$(SRCS_PATH)execution\
				$(SRCS_PATH)parsing\
				$(SRCS_PATH)validations\
				$(SRCS_PATH)expansion\
				$(SRCS_PATH)path\
				$(SRCS_PATH)free\
				$(SRCS_PATH)signals\
				$(SRCS_PATH)redirections

OBJS			=	$(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=.o)))

$(OBJS_PATH)%.o: %.c
				mkdir -p $(OBJS_PATH)
				$(CC) $(CFLAGS) $(CINC) -c $< -o $@

all	:		$(NAME)

$(NAME)	:	$(OBJS)
			echo "$(BLUE)Object files generated!$(RESET)"
			echo "$(YELLOW)Compiling libft...$(RESET)"
			$(MAKE) -sC $(LIBFT_PATH) $(LIBFT)
			$(CC) $(CFLAGS) $(CINC) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft $(CREAD)
			echo "$(GREEN)Minishell is ready to run! :)$(RESET)"

install:
			sudo apt-get install libreadline-dev
			echo"$(GREEN)Readline ready!$(RESET)"

clean:
			make -sC $(LIBFT_PATH) clean
			rm -rf $(OBJS_PATH)

fclean:		clean
			make -sC $(LIBFT_PATH) fclean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
