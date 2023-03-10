/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:49:16 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/10 15:36:16 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_status;

void	prompt_loop(t_data *data);

/* reset_mns
1. Permet de comprendre comment recuperer les commandes et dans ce cas les imprime
*/

void ft_print_lst(t_list *cmd)
{
	char	**a;

	while (cmd)
	{
		a = ((t_node *)cmd->content)->full_cmd;
		printf("%s \n", a[0]);
		cmd = cmd->next;
	}
}

/* reset_mns
1. Permet de reboucler et relancer un nouveau prompt une fois que l'utilisateur a fini de
remplir sa ligne de commande
*/

static void	reset_mns(t_data *data)
{
	free(data->text);
	prompt_loop(data);
}

/* parse_args
1. subsplit est un tableau qui prend la i-eme ligne de args et recherche <|> dans cette ligne 
et le separe
2. puis ft_tab_replace_in rajoute la nouvelle ligne conteannt <|> dans le tableau initial
3. redivise le tableau args s'il trouve un <|> puis incorpore dans le tableau original 	
les nouvelles lignes avec un <|>. En resumé rajoute une ligne au tableau s'il trouve un 	
<|>
4. Rempli une liste chainée avec pour chaque noeud une structure qui contient un tableau
avec la commande puis les "options", un tableau avec le PATH de la commande, le fd in et
le fd out.
*/

static void	*parse_args(char **args, t_data *data)
{
	int	i;
	char	**subsplit;

	i = -1;
	while (args && args[++i] && data)
	{
		subsplit = ft_cmdsubsplit(args[i], "<|>");
		ft_tab_replace_in(&args, subsplit, i);
		i += ft_tablen(subsplit) - 1;
		ft_free_tab(&subsplit);
	}
	data->cmds = fill_nodes(args);
	ft_print_lst(data->cmds);
	if (!data->cmds)
		return (data);
	i = ft_lstsize(data->cmds);
	if (args)
	{
		ft_lstclear(&data->cmds, free_content);
		return (NULL);
	}
	return (data);
}

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

/* prompt_loop - args est le tableau contenant sur chaque ligne chaque du text du prompt
1. Lance le prompt "minishell$ " et stock ce qui sera ecrit dans la structure data (readline)
2. Stock l'historique de ce qui a ete ecrit dans le prompt (add_history)
3. Premier elagage du text en input, trie et stock chaque mot dans un tableau et separe 
les mots s'il trouve un espace, tout ce qui se trouve entre "" ou '' est considere comme
un mot a part entiere (ft_cmdtrim)
4. Deuxieme elagage, cette fois ci on separe les <|>, puis on rempli la liste chainée des infos
sur les commandes les pipes les redirections etc (parse_args)
*/

void	prompt_loop(t_data *data)
{
	char	**args;
	t_node	*node;

	data->text = readline("minishell$ ");
	add_history(data->text);
	args = ft_cmdtrim(data->text, " ");
	parse_args(args, data);
	if (data && data->cmds)
		node = data->cmds->content;
	if (data && data->cmds)
		ft_lstclear(&data->cmds, free_content);
	//printf("%s", data->cmds->content);
	reset_mns(data);
}

/* main
1. Copie de l'environnement
2. Gestion des signaux ctrl-C et ctrl-/
3. Recuperer où on est dans l'arborescence
4. Lancer l'affichage du prompt qui est dans une boucle infini et seul un signal
peut nous faire quitter le minishell normalement
*/

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