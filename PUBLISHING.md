# Publishing (VS Code Marketplace + optional Open VSX)

This is a standard VS Code theme extension. It works in **VS Code** and **Cursor** because both are VS Code-compatible.

## 0) Before you publish

1. Update `package.json`:
   - `publisher`: your Marketplace publisher id (e.g. `silviya-ruzhina`)
   - `name`: extension id (must be unique, e.g. `silvi-midnight`)
   - `displayName`, `description`
   - bump `version` (Marketplace requires increasing versions)
2. Optional but recommended:
   - Add an icon (`"icon": "assets/icon.png"`)
   - Add screenshots (and reference them from `README.md`)

## 1) Publish to VS Code Marketplace (Microsoft)

### Prereqs

- Install **Node.js LTS**
- Install `vsce`:
  - `npm i -g @vscode/vsce`

### Create a publisher

1. Go to `https://marketplace.visualstudio.com/manage`
2. Create a **publisher** (remember the publisher id).

### Create a Personal Access Token (PAT)

1. Go to Azure DevOps: `https://dev.azure.com/`
2. Create an organization (any name is fine).
3. User Settings → **Personal access tokens** → New Token
4. Scope: **Marketplace** → **Manage**

### Package + publish

From the extension folder:

- Package (local testing): `vsce package --allow-missing-repository`
- Publish: `vsce publish -p <YOUR_PAT> --allow-missing-repository`

This produces a `.vsix` you can also install locally.

> Tip: If you want images/relative links in `README.md` to render correctly on the Marketplace page, add a `"repository"` URL to `package.json` (or use `--baseContentUrl` / `--baseImagesUrl`).

### Notes (shell + token safety)

- If you use **PowerShell**, env var syntax is: `$env:VSCE_PAT="<YOUR_PAT>"`.
- If you use **Command Prompt (cmd.exe)**, env var syntax is: `set VSCE_PAT=<YOUR_PAT>`.
- Never paste your PAT into chats or commits; if you accidentally shared it, revoke it in Azure DevOps and create a new one.

## 2) (Optional) Publish to Open VSX

Some VS Code forks use **Open VSX**. If you want to cover those too:

1. Create an account + token at `https://open-vsx.org/`
2. Install the publisher CLI:
   - `npm i -g ovsx`
3. Publish:
   - `ovsx publish -p <YOUR_OPENVSX_TOKEN>`
