Basedir="$(dirname "$(realpath "$0")")"
if [ -z ${var+x} ];
then
	Prefix="$Basedir/../../Build"
fi

InstallPath="$Prefix/Include/Utility/"

mkdir "$InstallPath" -p
cp "$Basedir/../../../../../Utility/Include/." "$InstallPath" -r
