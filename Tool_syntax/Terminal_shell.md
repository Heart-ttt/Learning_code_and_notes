| 命令 | 说明 | 示例 |
|------|------|------|
| `ls` | 列出目录内容 | `ls -l`（详细列表），`ls -a`（含隐藏文件） |
| `cd` | 切换目录 | `cd ～`（回家目录），`cd ..`（返回上一级） |
| `pwd` | 显示当前路径 | `pwd` |
| `mkdir` | 创建目录 | `mkdir -p dir1/dir2`（递归创建） |
| `rm` | 删除文件/目录 | `rm file.txt`，`rm -rf dir/`（强制删除目录）⚠️ |
| `cp` | 复制文件/目录 | `cp a.txt b.txt`，`cp -r src/ dest/` |
| `mv` | 移动或重命名 | `mv old.txt new.txt`，`mv file ./dir/` |
| `touch` | 创建空文件或更新时间戳 | `touch app.log` |

| 选项 | 全称 | 作用 |
|------|------|------|
| `-i` | `--interactive` | 交互模式：每删一个文件都问你 `rm: remove regular file 'a.txt'?` |
| `-r` | | 递归 |
| `-f` | | 强制(跳过所有确认提示) |
| `-v` | `--verbose` | 显示删除过程：打印每个被删的文件名 |
| `-d` | `--dir` | 删除空目录（类似 `rmdir`） |
| `--preserve-root` | （默认启用） | 禁止递归删除根目录 `/`（安全保护） |
| `--no-preserve-root` | | 禁用保护（极度危险！） |

