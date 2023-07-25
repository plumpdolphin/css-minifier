# css-minifier
A simple, fast, rootin-and-tootin CSS minifier CLI tool to take your CSS game to the next, much-smaller level!

The tool is designed to be used with UNIX-based piping to allow for easy integration into a variety of build systems. The tool takes in a CSS file as a string through system `stdin`, processes the code, and spits out the result to `stdout`. Simple as that!

In order to use the tool, you'll need to pipe the CSS code to the executable. This can be done on GNU Linux using `cat` like this:

```bash
cat index.css | ./css-minify > index.min.css
```

In the example, `cat` will read out the file contents to `stdin` and run the minifier executable. The minifier's stdout is then written to `index.min.css`. Et voilà! Your CSS is ready for primetime.

To do the same thing in Windows, you can use the `type` command which is equivalent to GNU `cat`. i.e.
```cmd
type index.css | css-minify.exe > index.min.css
```

And that's all there is to it!

Good luck on your projects, and happy coding!