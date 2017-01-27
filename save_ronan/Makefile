##
## Makefile for malloc in /home/ronan/rendu/PSU_2016_malloc
## 
## Made by Ronan Boiteau
## Login   <ronan.boiteau@epitech.net>
## 
## Started on  Tue Jan 24 10:34:45 2017 Ronan Boiteau
## Last update Wed Jan 25 11:15:59 2017 Ronan Boiteau
##

INC_DIR	= include/

CC		= gcc
CFLAGS		+= -I $(INC_DIR)
CFLAGS		+= -Wall -Wextra
CFLAGS		+= -fPIC
# CFLAGS		+= -Werror
CFLAGS		+= -g3

RM		= rm -f

NAME		= libmy_malloc.so

SRCS_DIR	= src/
SRCS_FILES	= malloc.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -fPIC -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
