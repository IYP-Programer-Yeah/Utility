Basedir="$(dirname "$(realpath "$0")")"
if [ -z ${Prefix+x} ];
then
	Prefix="$Basedir/../../Build"
fi

InstallPath="$Prefix/Include/Utility/"

mkdir "$InstallPath" -p
cp "$Basedir/../../../../../Utility/Include/." "$InstallPath" -r
