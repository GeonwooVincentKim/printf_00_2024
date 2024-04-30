# NAME = libftprintf.a
# CC = gcc
# FLAGS = -c
# LIBFT = ./libft/libft.a

# SRCS	= ft_change_base.c ft_count_output.c \
# 	ft_printf.c ft_tolower_all.c ft_treat_hexa.c \
# 	ft_treat_int.c ft_treat_point.c 
# 	ft_treat_something.c ft_treat_string.c \
# 	ft_treat_uint.c ft_treat_char.c ft_putstr_count.c

# SURPL_O = ft_change_base.o \
# 	ft_count_output.o \
# 	ft_printf.o \
# 	ft_tolower_all.o \
# 	ft_treat_hexa.o \
# 	ft_treat_int.o \
# 	ft_treat_point.o \
# 	ft_treat_something.o \
# 	ft_treat_string.o \
# 	ft_treat_uint.o \
# 	ft_treat_char.o \
# 	ft_putstr_count.o

# OBJS	= $(SRCS:.c=.o)

# $(NAME): $(OBJS)
# $(MAKE) -C ./libft
# cp libft/libft.a $(NAME)
# $(CC) $(FLAGS) $(SRCS)
# ar -rcs $(NAME) $(OBJS)

# all : $(NAME)

# clean :
# 	$(MAKE) clean -C ./libft
# 	rm -rf $(SURPL_O) 
# 	rm -rf $(OBJS)

# fclean : clean
# 	$(MAKE) fclean -C ./libft
# 	rm -rf $(NAME)

# re : fclean all

# .PHONY:	all clean fclean re

# SRCS	= ft_printf.c ft_printf_utils.c ft_printf_utils_test.c libft_utils.c
# SRCS	= ft_printf_test.c ft_print_test_123.c ft_print_test_456.c ft_print_test_789.c ft_putstr_count.c
SRCS 	= ft_base.c ft_printf_utils.c ft_printf.c ft_treat_decimal.c ft_treat_non_primitive.c ft_treat_primitive.c
OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra	-Werror
LIBFT	= ./libft/libft.a

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean	all

.PHONY: all clean fclean re
