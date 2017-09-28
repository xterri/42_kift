#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    install_pocketsphinx.sh                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/28 14:19:11 by bpierce           #+#    #+#              #
#    Updated: 2017/09/28 14:19:11 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#install brew
#------------
mkdir $HOME/.brew && curl -fsSL https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C $HOME/.brew
mkdir -p /tmp/.$(whoami)-brew-locks
mkdir -p $HOME/.brew/var/homebrew
ln -s /tmp/.$(whoami)-brew-locks $HOME/.brew/var/homebrew/locks
export PATH="$HOME/.brew/bin:$PATH"
brew update && brew upgrade
echo "mkdir -p /tmp/.$(whoami)-brew-locks" >> ~/.zshrc
echo "export PATH=\"$HOME/.brew/bin:$PATH\"" >> ~/.zshrc

#install pocketsphinx
#--------------
brew tap watsonbox/cmu-sphinx
brew install --HEAD watsonbox/cmu-sphinx/cmu-sphinxbase
brew install --HEAD watsonbox/cmu-sphinx/cmu-pocketsphinx

#export sphinx to env variables
#------------------------------
export PATH="$HOME/.brew/bin:$PATH"

#end
#---
