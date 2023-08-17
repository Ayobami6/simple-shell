#!/usr/bin/bash

# check if a root user

user=`whoami`

packages=(git curl zsh)

if [ $user == "root" ]; then
	apt-get update

	for package in "${packages[@]}"; do
		hold=`dpkg -s $package`
		if [ -z $hold ]; then
			apt-get install $package -y
		fi
	done
	# install neovim
	curl -LO https://github.com/neovim/neovim/releases/latest/download/nvim.appimage
	chmod u+x nvim.appimage
	./nvim.appimage --appimage-extract
	mv squashfs-root /
	# check if nvim folder exist
	var=`find /usr/bin -name nvim`
	if [ "$var" ]; then
		rm -rf "$var"
	fi
	ln -s /squashfs-root/AppRun /usr/bin/nvim
	# install nvchad
	 git clone https://github.com/NvChad/NvChad ~/.config/nvim --depth 1
	 
	 # install syntax plugins and autosuggestion
	 git clone https://github.com/zsh-users/zsh-autosuggestions.git $ZSH_CUSTOM/plugins/zsh-autosuggestions
	 git clone https://github.com/zsh-users/zsh-syntax-highlighting.git $ZSH_CUSTOM/plugins/zsh-syntax-highlighting
	 # search and replace
	 sed -i 's/plugins=(git)/plugins=(git zsh-autosuggestions zsh-syntax-highlighting)/' ~/.zshrc
	 source ~/.zshrc 

	 # install Ohmyzsh
	 sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"


else
	sudo apt-get update

	for package in "${packages[@]}"; do
		hold=`dpkg -s $package`
		if [ -z $hold ]; then
			sudo apt-get install $package -y
		fi
	done
	# install neovim
	curl -LO https://github.com/neovim/neovim/releases/latest/download/nvim.appimage
	chmod u+x nvim.appimage
	./nvim.appimage --appimage-extract
	sudo mv squashfs-root /
	# check if nvim folder exist
	var=`find /usr/bin -name nvim`
	if [ "$var" ]; then
		sudo rm -rf "$var"
	fi
	sudo ln -s /squashfs-root/AppRun /usr/bin/nvim
	# install nvchad
	 git clone https://github.com/NvChad/NvChad ~/.config/nvim --depth 1
	 
	 # install syntax plugins and autosuggestion
	 git clone https://github.com/zsh-users/zsh-autosuggestions.git $ZSH_CUSTOM/plugins/zsh-autosuggestions
	 git clone https://github.com/zsh-users/zsh-syntax-highlighting.git $ZSH_CUSTOM/plugins/zsh-syntax-highlighting
	 # search and replace
	 sed -i 's/plugins=(git)/plugins=(git zsh-autosuggestions zsh-syntax-highlighting)/' ~/.zshrc
	 source ~/.zshrc

	 # install Ohmyzsh
	 sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
fi
