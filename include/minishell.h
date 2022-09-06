/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:54:19 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:28:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h> // STDIN_FILENO, STDOUT_FILENO, write, close
# include <stdio.h> // printf
# include <readline/readline.h> // readline
# include <readline/history.h> // add_history, clear_history
# include <signal.h> // signal, SIGINT, SIGQUIT
# include <sys/wait.h> // waitpid
# include <fcntl.h> // open, O_RDONLY, O_WRONLY, O_RDWR, O_CREAT, O_TRUNC
# include <errno.h> // errno, EACCES, ENOENT
# include "../libft/include/libft.h"

/*
 * This is the t_token structure. It holds the token_type (ex: T_PIPE),
 * the string with its content (ex "|") and a pointer to the next
 * token. It can also be (type: T_WORD, value: "echo"), for example, no
 * only operators.
 */
typedef struct s_token
{
	char			*token_value;
	int				token_type;
	struct s_token	*next;
}	t_token;

/*
 * This is the main parsing struct. It holds the original input
 * and the list of tokens.
 */
typedef struct s_parser
{
	char		*input;
	t_token		*tokens;
}	t_parser;

/*
 * This is the command struct. It holds all the variables to the
 * execution of the command. The list of commands. redirections, endpoints
 * an boolean for whether is ouoed, the exec list, path and envp for 
 * execve, fd_in and out, fd for the pipe, error_number and file for
 * errno and a pointer to next node.
*/
typedef struct s_cmd
{
	int				id;
	t_token			*commands;
	t_token			*redirections;
	int				endpoint;
	int				is_piped;
	char			**exec;
	char			*exec_path;
	char			**envp;
	int				fd_out;
	int				fd_in;
	int				fd_pipe[2];
	int				error_number;
	char			*filename;
	struct s_cmd	*next;
}	t_cmd;

/*
  * Entries in a hashtable are reffered as key-value pair.
  * This struct is used to store and handle them.
  */
typedef struct s_hashpair {
	char				*pair_key;
	char				*pair_value;
	int					location;
	struct s_hashpair	*next;
}	t_hashpair;

/*
 * This struct contains all the necessary information to manage the hashtable
 * for this project.
*/
typedef struct s_hashtable {
	t_hashpair	**pair_list;
	size_t		size;
	size_t		count;
}	t_hashtable;

/*
 * This is the core of the minishell. It contains the structures
 * to the main steps of the program: the parser, the executor 
 * and also the exit code and environment variables that are 
 * called and altered through the program.
*/
typedef struct s_minishell {
	t_hashtable	*envp;
	t_parser	*parser;
	t_cmd		*command;
	int			exit_code;
}	t_minishell;

/*
 * e_token_type: an enum for token_type:
 * T_WORD: any command, option or argument
 * T_REDIR_OUT: ">" shoud redirect output
 * T_REDIR_IN "<" should redirect input
 * T_REDIR_OUT_APPEND: ">>" should redirect output in append mode
 * T_HEREDOC: "<<" should be given a deliiter, the read the input 
 * until a line containing the delimiter is seen.
 * T_PIPE: should behave like pipe
*/
enum e_token_type {
	T_WORD,
	T_REDIR_OUT,
	T_REDIR_OUT_APPEND,
	T_REDIR_IN,
	T_HEREDOC,
	T_PIPE,
};

/*
 * e_location: an enum for the hashtables available: the GLOBAL
 * and the LOCAL.
*/
enum e_location {
	GLOBAL,
	LOCAL
};

/*
 * e_file_descriptor: an enum for the file descriptors opened.
 * in, out and in + out.
 */
enum e_file_descriptor {
	IN,
	OUT,
	IN_OUT
};

/*
* Global variables can be accessed from anywhere in the program. They are
* automatically initialized to 0. The "extern" keyword is used to means that
* the variable is defined in another file. The variable can't be declared in
* the header file because it would be declared more than once (if the header
* file is included in more than one file) since it causes a multiple definition
* error. Global variable are used in this project since the allow us to properly
* work with exit status using signals.
*/
extern t_minishell	g_minishell;

/* 
 * Function Prototypes (technical documentation is at every file)
*/
char				*get_command_path(t_cmd *cmd);
void				close_all_file_descriptors(void);
void				close_single_file_descriptor(t_cmd *command, int fd_type);
int					heredoc(char *limiter);
void				set_command_endpoints(t_cmd **cmd,
						t_token **list, int *prev);
void				heredoc_parent_signal(void);
void				heredoc_child_signal(void);
int					exit_builtin(char **exec);
int					echo_builtin(char **exec);
int					export_builtin(char **exec);
int					unset_builtin(char **exec);
int					env_builtin(t_cmd *cmd);
int					cd_builtin(char **exec);
int					pwd_builtin(void);
void				expand_redirections(t_cmd *cmd);
void				quote_expansion(t_token *token, int start, int *size);
void				free_pairs(t_hashpair *pair);
void				expand_dollar_and_quotes(t_token **token);
void				token_list(const char *input, size_t size);
char				*get_pwd(void);
int					is_minishell_command(t_cmd *cmd);
int					is_forked_command(t_cmd *cmd);
void				send_to_execution_in_child(t_cmd *cmd);
void				send_to_execution_in_parent(t_cmd *cmd);
void				child_execution(t_cmd *command);
void				wait_pids(int pid[1024], int id);
void				open_necessary_pipes(void);
int					define_redirection_fds(void);
void				parent_signals(void);
void				child_signals(void);
void				start_execution(void);
void				command_execution(t_cmd **cmd);
int					start_tokenization_process(void);
char				**convert_to_array(t_token *token);
int					is_valid_identifier(char *key);
void				free_envp(t_cmd *command);
int					heredoc_error(int *fd);
void				heredoc_to_pipe(char *limiter, int *fd);
void				replace_pair(char *key, char *value);
void				export_pair(char *key, int new_location);
void				free_minishell(void);
void				free_export_pwd_oldpwd(char **exec);
t_parser			*init_parser_struct(void);
char				*get_pair_key(char *pair);
char				*get_pair_value(char *pair);
char				**export_pwd_oldpwd(char *pwd, char *oldpwd);
void				free_path(char **path);
void				free_minishell(void);
void				free_command_struct(void);
void				free_execution_list(char **exec);
void				free_parser_struct(void);
void				free_tokens(t_token **list);
void				return_error(char *filename, int error_number);
int					is_redirection(int prev, int token_type);
void				create_execution_envp(t_cmd *cmd);
char				**parameter_expansion(t_token *token, int *index);
void				free_envp(t_cmd *cmd);
void				check_access(t_cmd *command, char **path_list, char **path);
char				*split_path(t_cmd *command);
char				*get_command_path(t_cmd *command);
int					is_expandable(char c);
void				free_expansion_array(char **str, char *next);
char				*get_pair_key(char *variable);
char				*get_pair_value(char *variable);
t_hashtable			*init_hashtable_struct(void);
void				send_env_to_hashtable(char **variables);
void				free_hashtable(void);
void				insert_pair(char *key, char *value, int location);
int					get_location(char *key);
char				*key_lookup(char *key);
unsigned long int	hash_function(char *key, unsigned int size);
int					is_valid_token(const char *input,
						size_t index, size_t prev);
t_token				*create_new_token(char *token, int is_sig);
t_token				*token_copy(t_token *original);
void				command_path_error(t_cmd *command, int nb);
void				token_add_back(t_token **head, t_token *new_token);
size_t				get_lst_size(t_token *token);
int					define_token_type(char *token);
int					check_bash_grammar(void);
int					is_valid_pipe(t_token *token, int pos);
int					is_valid_redirection(t_token *token);
int					is_closed_quotation_mark(t_token *token);
t_cmd				*init_command_struct(int id);
void				command_add_back(t_cmd *node);
void				command_add_front(t_cmd *node);
void				fill_command_table(void);
void				start_expansion(void);
void				open_redirection_files(int redir_type, char *filename,
						t_cmd *command);
void				create_execution_array(void);
void				expand_parameter(t_token **token, int *pos);
void				expand_quotes(t_token **token, int *pos, char quote);
int					has_matching_quote(const char *input, size_t index);
int					is_valid_file_descriptor(t_cmd *command);

#endif
