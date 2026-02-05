{
  description = "QMK Firmware";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-25.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        overlays = [ ];
        pkgs = import nixpkgs {
          inherit system overlays;
        };
        buildInputs = with pkgs; [
        ];
        nativeBuildInputs = with pkgs; [
          (qmk.overridePythonAttrs (old: {
            propagatedBuildInputs = old.propagatedBuildInputs or [] ++ [
              # Required by qmk_firmware <= 0.26.9.
              # Change to just use plain qmk once NixOS/nixpkgs#412129 is in my nixpkgs commit.
              python3Packages.appdirs
            ];
          }))
          clang-tools
        ] ++ buildInputs;
      in with pkgs; rec
      {
        devShells.default = mkShell {
          inherit nativeBuildInputs;

          SKIP_GIT = 1;
        };
      }
    );
}
