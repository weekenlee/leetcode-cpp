package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"regexp"
	"strings"
)

func getnodename(line string) (string, string) {
	reg := regexp.MustCompile(`\"(.+?)\"`)
	result := reg.FindAllString(line, -1)
	if len(result) > 0 {
		name := strings.TrimSpace(string(result[0][1 : len(result[0])-1]))
		return string(name[:len(name)-1]), string(name[len(name)-1])
	}
	return "", ""
}

func process(linenum int, lines []string) {
	nodename, nodetype := getnodename(lines[linenum+1])
	fmt.Println(nodename, nodetype)
}

func readfile(filename string) {
	fi, err := os.Open(filename)
	if err != nil {
		fmt.Println("Error read " + filename)
	}
	defer fi.Close()

	fd, err := ioutil.ReadAll(fi)
	if err != nil {
		fmt.Println("Error read " + filename)
	}

	lines := strings.Split(string(fd), "\n")

	for i, v := range lines {
		if strings.Contains(v, " ) ------------------------------------------------------------------------------------------------------------------------------") {
			process(i, lines)
		}
	}
}

func main() {
	readfile("电厂侧合甲线a相重合闸.lis")
}
