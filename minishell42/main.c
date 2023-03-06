/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:49:16 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/06 12:30:20 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	prompt_loop(t_data *data);

void find_pwd(t_data  *data, char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PWD", 4) == 0)
			data->pwd = *envp + 4;
        if (ft_strncmp(*envp, "OLDPWD", 7) == 0)
			data->old_pwd = *envp + 7;
		envp++;
	}
}

void	reset_mns(t_data *data)
{
	//ft_simple_cmdsclear(&data->simple_cmds);
	free(data->text);
	/*if (data->pid)
		free(data->pid);*/
	//free_arr(data->paths);
	//implement_data(data);
	//data->reset = true;
	prompt_loop(data);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_tabdup(char **tab)
{
	char	**t_dup;
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	t_dup = ft_calloc(sizeof(char *), i + 1);
	if (!t_dup)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		t_dup[i] = ft_strdup(tab[i]);
		if (t_dup[i] == NULL)
		{
			free_tab(t_dup);
			return (t_dup);
		}
		i++;
	}
	return (t_dup);
}

void	sigint_handler(int sig)
{
	ioctl(0, TIOCSTI, "\n");
	rl_replace_line("", 0);
		rl_on_new_line();
	(void) sig;
}

void	sigquit_handler(int sig)
{
	ft_putstr_fd("Quit: ", 2);
	ft_putnbr_fd(sig, 2);
	ft_putchar_fd('\n', 2);
}

/*void ft_text_trim(t_data *data)
{
	
}*/

void remove_double_spaces(char *str)
{
    int i = 0;
	int j = 0;
    int quote_count = 0, single_quote_count = 0;

    while (str[i] != '\0') {
        if (str[i] == '"' && (i == 0 || str[i - 1] != '\\')) {
            quote_count++;
        }
        if (str[i] == '\'' && (i == 0 || str[i - 1] != '\\')) {
            single_quote_count++;
        }
        if (str[i] == ' ' && str[i + 1] == ' ' && quote_count % 2 == 0 && single_quote_count % 2 == 0) {
            continue;
        }
        str[j++] = str[i++];
    }
    str[j] = '\0';
}

static int	ft_count_words(const char *s, char *c, int counts[2])
{
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	while (s[counts[0]] != '\0')
	{
		if (!ft_strchr(c, s[counts[0]]))
		{
			counts[1]++;
			while ((!ft_strchr(c, s[counts[0]]) || q[0]) && s[counts[0]] != '\0')
			{
				if (!q[1] && (s[counts[0]] == '\"' || s[counts[0]] == '\''))
					q[1] = s[counts[0]];
				q[0] = (q[0] + (s[counts[0]] == q[1])) % 2;
				q[1] *= q[0] != 0;
				counts[0]++;
			}
			if (q[0])
				return (-1);
		}
		else
			counts[0]++;
	}
	return (counts[1]);
}

static char	**ft_fill_array(char **aux, char const *s, char *set, int i[3])
{
	int		s_len;
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	s_len = ft_strlen(s);
	while (s[i[0]])
	{
		while (ft_strchr(set, s[i[0]]) && s[i[0]] != '\0')
			i[0]++;
		i[1] = i[0];
		while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
		{
			q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
			q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2;
			i[0]++;
		}
		if (i[1] >= s_len)
			aux[i[2]++] = "\0";
		else
			aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
	}
	return (aux);
}

char	**ft_cmdtrim(char const *s, char *set)
{
	char	**aux;
	int		nwords;
	int		i[3];
	int		counts[2];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	counts[0] = 0;
	counts[1] = 0;
	if (!s)
		return (NULL);
	nwords = ft_count_words(s, set, counts);
	if (nwords == -1)
		return (NULL);
	aux = malloc((nwords + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux = ft_fill_array(aux, s, set, i);
	aux[nwords] = NULL;
	return (aux);
}


void	prompt_loop(t_data *data)
{
	char	*tmp;
	char	**first_pars;

	data->text = readline("minishell$ ");
	add_history(data->text);
	tmp = ft_strtrim(data->text, " ");
	free(data->text);
	data->text = tmp;
	if (!data->text)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	remove_double_spaces(data->text);
	first_pars = ft_cmdtrim(data->text, " ");
	printf("%s \n", first_pars[0]);
	/*if (data.text[0] == '\0')
		return (reset_tools(data));*/
	reset_mns(data);
}

int	main(int argc, char **argv, char **envp)
{
    t_data  data;
	
    if (argc == 1 && !argv[1])
    {
        data.env = ft_tabdup(envp);
        signal(SIGINT, sigint_handler);
	    signal(SIGQUIT, SIG_IGN);
        find_pwd(&data, envp);
		prompt_loop(&data);
    }
    else
        write(2, "Invalid number of arguments.\n", 28);
    return (0);
	
}