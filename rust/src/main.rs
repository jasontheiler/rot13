fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args = std::env::args();
    let reader: Box<dyn std::io::Read> = if args.len() > 1 {
        let input = args.skip(1).collect::<Vec<_>>().join(" ") + "\n";
        Box::new(std::io::Cursor::new(input))
    } else {
        Box::new(std::io::stdin())
    };

    std::io::copy(&mut Rot13Reader::from(reader), &mut std::io::stdout())?;

    Ok(())
}

struct Rot13Reader<T: std::io::Read>(T);

impl<T: std::io::Read> From<T> for Rot13Reader<T> {
    fn from(value: T) -> Self {
        Self(value)
    }
}

impl<T: std::io::Read> std::io::Read for Rot13Reader<T> {
    fn read(&mut self, buf: &mut [u8]) -> std::io::Result<usize> {
        let n = self.0.read(buf)?;
        for b in buf {
            let a = match b {
                b'a'..=b'z' => b'a',
                b'A'..=b'Z' => b'A',
                _ => continue,
            };
            *b = ((*b - a + 13) % 26) + a
        }
        Ok(n)
    }
}
