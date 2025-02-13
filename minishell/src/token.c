/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:50:51 by talin             #+#    #+#             */
/*   Updated: 2025/01/23 13:19:35 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_token(t_lexer *lexer, char *token)
{
	char	**new_tokens;
	int		i;

	new_tokens = malloc(sizeof(char *) * (lexer->token_count + 1));
	if (!new_tokens)
	{
		perror("malloc");
		exit (EXIT_FAILURE);
	}
	i = -1;
	while (++i < lexer->token_count)
		new_tokens[i] = lexer->tokens[i];
	new_tokens[lexer->token_count] = token;
	free(lexer->tokens);
	lexer->tokens = new_tokens;
	lexer->token_count++;
}

int	ft_tokenize_one(t_lexer *lexer, char *input, int *i)
{
	char	*token;

	if ((input[*i] == '>' && input[(*i + 1)] == '>') || \
	(input[*i] == '<' && input[(*i + 1)] == '<'))
	{
		token = malloc(3);
		if (!token)
			return (free_lexer(lexer), 0);
		token[0] = input[(*i)++];
		token[1] = input[(*i)++];
		token[2] = '\0';
		add_token(lexer, token);
	}
	else
	{
		token = malloc(2);
		if (!token)
			return (free_lexer(lexer), 0);
		token[0] = input[(*i)++];
		token[1] = '\0';
		add_token(lexer, token);
	}
	return (1);
}

char	*ft_tokenize_two_token(int start, int *i, char *input)
{
	char	*token;
	char	*combined;
	char	*temp;

	token = ft_strndup(input + start, *i - start + 1);
	(*i)++;
	start = *i;
	while (input[*i] && !ft_isspace(input[*i]) && \
	input[*i] != '|' && input[*i] != '<' && input[*i] != '>')
		(*i)++;
	if (start < *i)
	{
		combined = ft_strndup(input + start, *i - start);
		temp = ft_strjoin(token, combined);
		free(token);
		free(combined);
		token = temp;
	}
	return (token);
}

int	ft_tokenize_two(t_lexer *lexer, char *input, int *i)
{
	char	*token;
	char	quote;
	int		start;

	quote = input[(*i)];
	start = *i;
	if (input[(*i) + 1])
		(*i)++;
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (input[*i] == quote)
	{
		token = ft_tokenize_two_token(start, i, input);
		add_token(lexer, token);
	}
	else
	{
		perror("unclosed quote");
		free_lexer(lexer);
		return (0);
	}
	return (1);
}

void	ft_tokenize_three(t_lexer *lexer, char *input, int *i)
{
	int		start;
	char	*token;

	start = *i;
	while (input[*i] && !ft_isspace(input[*i]) && \
	input[*i] != '|' && input[*i] != '<' && input[*i] != '>')
		(*i)++;
	token = ft_strndup(input + start, *i - start);
	add_token(lexer, token);
}

int	ft_tokenize_four(t_lexer *lexer, char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (!input[i])
			break ;
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			if (!ft_tokenize_one(lexer, input, &i))
				return (0);
			continue ;
		}
		if (input[i] == '"' || input[i] == '\'')
		{
			if (!ft_tokenize_two(lexer, input, &i))
				return (0);
			continue ;
		}
		ft_tokenize_three(lexer, input, &i);
	}
	return (1);
}
