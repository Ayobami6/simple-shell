#!/usr/bin/bash

# install syntax plugins and autosuggestion
git clone https://github.com/zsh-users/zsh-autosuggestions.git /root/.oh-my-zsh/custom/plugins/zsh-autosuggestions
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git /root/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting
# search and replace
sed -i 's/plugins=(git)/plugins=(git zsh-autosuggestions zsh-syntax-highlighting)/' ~/.zshrc

read -p "Do you want to set vi as alias for nvim? (Y/n)" ans

if [ $ans == "y" ] || [ $ans == "Y" ]; then
	alias vi="nvim"
	echo "You can now open your nvim with vi"
fi
