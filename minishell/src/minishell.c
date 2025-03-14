/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:35:12 by talin             #+#    #+#             */
/*   Updated: 2025/01/23 16:02:49 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_lexer	*tokenize(char *input)
{
	t_lexer	*lexer;
	char	**new_tokens;
	int		i;

	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->tokens = NULL;
	lexer->token_count = 0;
	if (!ft_tokenize_four(lexer, input))
		return (NULL);
	new_tokens = malloc(sizeof(char *) * (lexer->token_count + 1));
	if (!new_tokens)
		return (free_lexer(lexer), NULL);
	i = -1;
	while (++i < lexer->token_count)
		new_tokens[i] = lexer->tokens[i];
	free(lexer->tokens);
	lexer->tokens = new_tokens;
	lexer->tokens[lexer->token_count] = NULL;
	return (lexer);
}

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_lexer		*lexer;
	t_data		data;
	int			i;
	(void)ac;
	(void)av;

	i = 0;
	while (env[i])
		i++;
	data.env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!data.env)
		return (1);
	i = -1;
	while (env[++i])
		data.env[i] = ft_strdup(env[i]);
	data.env[i] = NULL;
	while (1)
	{
		input = readline("minishell > ");
		if (!input)
			break ;
		if (*input)
			add_history(input);
		input[ft_strcspn(input, "\n")] = '\0';
		lexer = tokenize(input);
		if (lexer)
		{
			printf("Tokens:\n");
			i = 0;
			while (lexer->tokens[i])
			{
				printf("[%s]\n", lexer->tokens[i]);
				i++;
			}
			printf("........................................\n");
			if (sanitize_tokens(lexer->tokens) != 0)
			{
				free_lexer(lexer);
				return (0);
			}
			data.commands = parse_tokens(lexer);
			if (data.commands) {
				parameter_expansion(data.commands, data.env);
				print_commands(data.commands);
				// free_commands(data.commands);
		    }
			if (!execute_commands(&data))
				break ;
		}
		free_lexer(lexer);
		free(input);
	}
	i = -1;
	while (data.env[++i])
		free(data.env[i]);
	free(data.env);
	return (0);
}
