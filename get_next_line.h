/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:05:25 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/15 16:10:41 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

# define UPHEX "0123456789ABCDEF"
# define LOWHEX "0123456789abcdef"
# define DEC "0123456789"

# ifdef BUFFER_SIZE
    # define BF_SIZE BUFFER_SIZE
#else 
    # define BF_SIZE BUFSIZ
#endif


#endif
