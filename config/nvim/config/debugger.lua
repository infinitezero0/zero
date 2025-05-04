local dap = require("dap")

-- NOTE: configure adapters
dap.adapters.codelldb = {
  type = "executable",
  command = "/home/zero/.local/share/nvim/mason/bin/codelldb", -- or if not in $PATH: "/absolute/path/to/codelldb"
}
dap.adapters.cppdbg = {
  id = "cppdbg",
  type = "executable",
  command = "/home/zero/.local/share/nvim/mason/bin/OpenDebugAD7", -- or if not in $PATH: "/absolute/path/to/OpenDebugAD7"
  options = { detached = false },
}
dap.adapters.gdb = {
  type = "executable",
  command = "gdb",
  args = { "--interpreter=dap", "--eval-command", "set print pretty on" },
}
-- NOTE: filetype configurations
dap.configurations.cpp = {
  {
    name = "Launch (codelldb)",
    type = "codelldb",
    request = "launch",
    program = function()
      return vim.fn.input("Path to executable: ", vim.fn.getcwd() .. "/build/", "file")
    end,
    cwd = "${workspaceFolder}",
    stopOnEntry = false,
  },
  {
    name = "Launch (gdb)",
    type = "cppdbg",
    MIMode = "gdb",
    request = "launch",
    miDebuggerPath = "/usr/bin/gdb",
    program = function()
      return vim.fn.input("Path to executable: ", vim.fn.getcwd() .. "/", "file")
    end,
    cwd = "${workspaceFolder}",
    setupCommands = {
      {
        description = "Enable pretty-printing for gdb",
        ignoreFailures = true,
        text = "-enable-pretty-printing",
      },
    },
    stopAtBeginningOfMainSubprogram = false,
  },
  {
    name = "Select and attach to process",
    type = "cppdbg",
    request = "attach",
    program = function()
      return vim.fn.input("Path to executable: ", vim.fn.getcwd() .. "/", "file")
    end,
    pid = function()
      local name = vim.fn.input("Executable name (filter): ")
      return require("dap.utils").pick_process({ filter = name })
    end,
    cwd = "${workspaceFolder}",
  },
}
dap.configurations.c = dap.configurations.cpp
dap.configurations.rust = dap.configurations.cpp
