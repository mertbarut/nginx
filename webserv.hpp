/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:55:09 by mbarut            #+#    #+#             */
/*   Updated: 2022/04/25 14:42:22 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV
# define WEBSERV

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>

#ifndef PORT
# define PORT 8080
#endif

#endif