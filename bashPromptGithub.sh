function getGitBranch {
	git branch --no-color 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ (\1)/'
}
function getGitStatus {
	[ -n "`git status -s 2>/dev/null`" ]
}
bashPromptGithub() {
	local reset="\[\033[0m\]"          # Text Reset
	local Black="\[\033[1;30m\]"       # Black Bold
	local Red="\[\033[1;31m\]"         # Red Bold
	local Green="\[\033[1;32m\]"       # Green Bold
	local Yellow="\[\033[1;33m\]"      # Yellow Bold
	local Blue="\[\033[1;34m\]"        # Blue Bold
	local Purple="\[\033[1;35m\]"      # Purple Bold
	local Cyan="\[\033[1;36m\]"        # Cyan Bold
	local White="\[\033[1;37m\]"       # White Bold

	PS1="${Red}\u${reset}${White}@${Green}\h${reset}:${Blue}\w${reset}\$(getGitBranch)\$(getGitStatus)\\\$ "
}
bashPromptGithub
unset bashPromptGithub

# Remove Itens repetidos no bash_history:
export HISTCONTROL=ignoreboth
