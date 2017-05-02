const glob = require("glob");
const fs = require("fs");

// write Report 
const writeReport = (source) => {
    const title = source.split("/").slice(-1)[0].replace(".c","");
    const code = fs.readFileSync(source, "utf-8");
    let text;
    try {
        text = fs.readFileSync(`src/${number}/text/${title}.txt`, "utf-8");
    } catch (e) {
        text = "";
    }
    const str = `
# ${title}

## ソースコード

\`\`\`c
${code}
\`\`\`

## 出力

\`\`\`
${text}
\`\`\`

`;
    return str;
}


const number = Number(process.argv[2]);

const sources = glob.sync(`src/${number}/*.c`);

let report = "";
sources.forEach((value) => {
    report += writeReport(value);
});

console.log(report);
