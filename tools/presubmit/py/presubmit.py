import sys
import logging
import argparse

import pw_cli.log
from pw_presubmit import (git_repo, install_hook)

__LOG = logging.getLogger(__name__)

PRE_PUSH_HOOK_COMMANDS = ['bazelisk',
                          'run',
                          '@pigweed//pw_presubmit/py:format',
                          '--',
                          '--base',
                          'HEAD~1',
                          '--check']


def run(install: bool) -> int:
    """Runs presubmit checks. Installs git hook if necessary."""
    if install:
        install_hook.install_git_hook('pre-push',
                                      PRE_PUSH_HOOK_COMMANDS,
                                      git_repo.root())
        __LOG.info('Presubmit checks are now installed as a git hook.')
        return 0


    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--install',
                        action='store_true',
                        help='Install git hook for pre push operation.')

    return run(**vars(parser.parse_args()))


if __name__ == '__main__':
    pw_cli.log.install(logging.INFO)
    sys.exit(main())