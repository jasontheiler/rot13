package main

import (
	"io"
	"log"
	"os"
	"strings"
)

func main() {
	var r io.Reader
	if len(os.Args) > 1 {
		r = strings.NewReader(strings.Join(os.Args[1:], " ") + "\n")
	} else {
		r = os.Stdin
	}

	_, err := io.Copy(os.Stdout, rot13Reader{r})
	if err != nil {
		log.Fatal(err)
	}
}

type rot13Reader struct {
	r io.Reader
}

func (r13 rot13Reader) Read(p []byte) (n int, err error) {
	n, err = r13.r.Read(p)
	for i, b := range p {
		var a byte
		switch {
		case b >= 'a' && b <= 'z':
			a = 'a'
		case b >= 'A' && b <= 'Z':
			a = 'A'
		default:
			continue
		}
		p[i] = (b-a+13)%26 + a
	}
	return
}
