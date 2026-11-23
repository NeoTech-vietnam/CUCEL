# CUCEL

Independent NeoCam module copied from NeoLab firmware.

Implementation, public contracts, module.cmake and owned tests live here.
Product configuration is supplied by neocam_csw/Conf. See the integration
README for host tests, live overrides and publication instructions.

## Reference-project CI

Pushes to any branch, including main/master, run the reference projects selected
in `ci_targets.yml`. Tag pushes are excluded. The current target is
`NeoTech-vietnam/neocam_csw` on `feat/cucel`, using this module's exact pushed
commit as the `CUCEL` package. The module check follows the integration build
and reports its result.

Set repository Actions secret `INTEGRATION_DISPATCH_TOKEN` with Actions: Read and
write and Contents: Read-only on **neocam_csw**. The integration project's
main/default branch remains forbidden as a target, regardless of the module's
source branch.

## Documentation

Read the [published CUCEL specification](https://neotech-vietnam.github.io/CUCEL/specification.html)
or build the [reStructuredText documentation](docs/index.rst) from this repository.
