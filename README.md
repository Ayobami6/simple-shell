![Languages](https://img.shields.io/github/languages/top/Ayobami6/simple-shell)
![GitHub repo size](https://img.shields.io/github/repo-size/Ayobami6/simple-shell)
![GitHub issues](https://img.shields.io/github/issues/Ayobami6/simple-shell)
![GitHub closed issues](https://img.shields.io/github/issues-closed/Ayobami6/simple-shell)
![GitHub pull requests](https://img.shields.io/github/issues-pr/Ayobami6/simple-shell)
![GitHub closed pull requests](https://img.shields.io/github/issues-pr-closed-raw/Ayobami6/simple-shell)
![GitHub](https://img.shields.io/github/license/Ayobami6/simple-shell)
![GitHub Repo stars](https://img.shields.io/github/stars/Ayobami6/simple-shell?style=social)
![GitHub forks](https://img.shields.io/github/forks/Ayobami6/simple-shell?style=social)
![GitHub contributors](https://img.shields.io/github/contributors/Ayobami6/simple-shell)
![Github Release](https://img.shields.io/github/v/release/Ayobami6/simple-shell)

## Smart-Shell

Simple shell that runs most Unix commands with in built git command publish that does git add, git commit and commit at a
go and prompt for commit message, also contains inbuilt shell game tic-tac toe

![home](/imgs/f1.png)

## Installation

### Use this to download to the bin directory

### Note: Must have root access

```commandline
wget -O /bin/exec.zip https://github.com/Ayobami6/simple-shell/blob/master/zip/files.zip?raw=true
```

### Unzip the downloaded zipped files in the bin directory in your root

```commandline
unzip /bin/exec.zip -d /bin
```

## Usage

### type hsh to run the smart shell

```bash
hsh
```

Choose 1 or 2 or 3 to select smart shell options

choose 2 for games

![games](/imgs/f2.png)

Enter tic-tac for tic-tac game
```bash
tic-tac  
```
![tic-tac](/imgs/f3.png)

Using the publish command for git add, commit and push
Plublish all changes made to the specific git repo to github remote
```bash
publish
```
![publish](/imgs/f4.png)

![push](/imgs/f5.png)

## Run With docker 

Download and install docker on your PC

[Watch this Youtube movie to install docker on your machine](https://youtu.be/8C0LOqynLes)


Run
```bash
docker login
```
Pull the shell docker image with

```bash
docker pull ayobami6/simple-shell
```

Run the docker image interactively
```bash
docker run -it ayobami6/simple-shell:v1.0
```
or

```bash
docker run -it ayobami6/simple-shell
```
## Contributing 

You are welcome to create an issue if there are bugs which most definitely there are, any issue will be appreciated and
carefully looked in to.
Also, if you want to have your C game(s) included in the shell you can fork and create a pull request by adding your game function
inside the games directory and your game will be included with your full name. 

## Incoming 
V1.1
Features still unknown..
