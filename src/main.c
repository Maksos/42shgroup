/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:38:33 by maastie           #+#    #+#             */
/*   Updated: 2017/09/07 20:38:36 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int			main(int ac, char **av, char **env)
{
	if (ac != 1 || av[1] != NULL)
		return (ft_error(1, -1));
	if ((t = (t_term *)malloc(sizeof(t_term))) == NULL
		|| (d = (t_data *)malloc(sizeof(t_data))) == NULL)
		return (ft_error(2, -1));
	t->line = NULL;
	t->history = NULL;
	d->env = cpy_tab(d->env, env, 1); // add data if necessary
// HOME=/Users/maastie
// LOGNAME=maastie
// SHLVL=1
// PWD=/Users/maastie/Project/n42
// OLDPWD=/Users/maastie/Project/n42
// _=/usr/bin/env
	d->andor = 0;
	d->ph = 0;
	if ((begin_termcaps_read()) == -1)
		return (ft_error(4, -1));
	ft_free_all();
	return (0);
}
	//		Obligatoire
//0		// Built-in POSIX
						// cd -L et -P // error
		//		-	echo -n refresh termcaps

//1		// exec_it()
		//		-	check in env
		//		-	exec_in_line
		//		-	shllvl

//2		//	ERROR
		//		-	Ecrire les messages erreurs

						//		Bonus
							//0	 	-	sous shell
							//1		-	shell scipt
							//2		-	'\' '`' & >|
							//3		- 	!
							//4		-	globbing
							//5		-	job fg +- realisable
